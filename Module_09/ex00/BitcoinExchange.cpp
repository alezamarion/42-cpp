/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azamario <azamario@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 07:54:30 by azamario          #+#    #+#             */
/*   Updated: 2023/06/21 16:56:03 by azamario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

void bitcoinExchange( std::string csvFileName, std::string txtFileName )
{
    BitcoinExchange bitcoinData;

    getBitcoinData(bitcoinData, csvFileName);
    readInputAndExchangeData(bitcoinData, txtFileName);
}

/*	This function reads Bitcoin data from a file line by line, extracts the date and value from each line, 
	and inserts	them into a BitcoinExchange object's _map member variable. */
void getBitcoinData( BitcoinExchange &bitcoinData, std::string fileName ) //csvFilename
{
    std::ifstream file;
    std::string line;

    file.open(fileName.c_str());

    /*	The first line of the file is read and discarded using getline(file, line). This assumes that the first line 
		contains a header or some other information that is not relevant for the data extraction. */
	getline(file, line);

	// loop to read each subsequentline of file
    while (getline(file, line))
    {
        std::istringstream  stringStream; //used to read individual values from the line string
        std::string         date;	//store date
        double              value;	//store value

		/* The stringStream object is initialized with the current line using stringStream.str(line). 
		   This sets up the stringStream to read from the line string */
        stringStream.str(line);
        
		/* Used to extract a string value from stringStream until it encounters a comma (','). 
		   This assumes that the date value is expected to be present before the comma. */
		getline(stringStream, date, ',');
 
		/* Used to extract a double value from stringStream after the comma. This assumes that the Bitcoin value 
		   is present after the comma.*/
        stringStream >> value;

		/* The extracted date and value pair is then inserted into the _map member variable of the bitcoinData object 
		   using bitcoinData._map.insert(std::make_pair(date, value)). _map is a member variable of bitcoinData that 
		   stores the Bitcoin data in a map-like structure, where date is the key and value is the corresponding value. */
        bitcoinData._map.insert(std::make_pair(date, value));
    }
}

/*	This function reads input data from a file, validates the data, and calculates the exchanged value of Bitcoin 
	based on the provided exchange rate. */
void readInputAndExchangeData( BitcoinExchange &bitcoinData, std::string fileName ) //txtFilename
{
    std::ifstream   file;
    std::string     line;

    file.open(fileName.c_str());
	if (file.peek() == std::ifstream::traits_type::eof())
	{
        std::cerr << "Error: File is empty." << std::endl;
        return;
    }
    getline(file, line);
    if (!(line == "date | value"))
    {
        std::cout << "Error: bad input => \"" << line << "\"" << std::endl;
        return ;
    }
    while (getline(file, line))
    {
        std::string delimiter = " | ";
        std::string date;
        std::string stringValue;
    
        size_t pos = line.find(delimiter);  
		//If the delimiter is found at position 10, it indicates that both the date and value are present in the line. 
        if (pos == 10)
        {
            date = line.substr(0, pos); //extract date
            stringValue = line.substr(pos + delimiter.length()); //extract value
        }
		/* If the delimiter is not found at position 10, it means that only the date is present in the line. 
		   The entire line is assigned to date, and stringValue is set to an empty string. */
        else
        {
            date = line;
            stringValue = "";
        }   
        double value = std::atof(stringValue.c_str()); //value is converted to double
		if (!value)
            std::cout << "Error: not a valid value" << std::endl;
        else if (value > 1000)
            std::cout << "Error: too large number" << std::endl;
        else if (pos != 10 || !ValidDate(date))
            std::cout << "Error: bad input => | " << date << " |" << std::endl;
        else if (value < 0)
            std::cout << "Error: not a positive number" << std::endl;
		//If the extracted data passes all the validations, the function calculates the exchanged value of Bitcoin
	    else
            std::cout << date << " => " << value << " = " << value * exchangeRate(bitcoinData, date) << std::endl;
    }
}

/*	This function retrieves the exchange rate for a specified date from the _map member variable of the 
	BitcoinExchange object. If the exchange rate is not found for the given date, it recursively searches for the 
	exchange rate of the previous date until a matching exchange rate is found or no earlier dates are available.
*/

double exchangeRate(BitcoinExchange bitcoinData, std::string date)
{
	/* 1 - iterator it to store the iterator for the search result in the _map variable of the bitcoinData object.
	   2 - searches for specific date in map -> find() returns an iterator pointing to the found element if present
	   	   or returns 'bitcoinData._map.end() if the date is not found */
    std::map<std::string, double>::iterator it = bitcoinData._map.find(date);

    if (it != bitcoinData._map.end()) //exchange rate to specific date is found in the _map
        return (it->second); //returns the corresponding exchange rate value 'it->second'
    else
    {
        date = pastDate(date); //if not found, look for a past date
        
		/* recursively calls itself with the updated bitcoinData object and the new date value. This recursive call aims to search for the exchange rate 
		   of the previous date. The recursive call continues until a matching exchange rate is found in the _map or until the _map does not contain any 
		   earlier dates. When a matching exchange rate is found, the function returns the corresponding value. */
		return (exchangeRate(bitcoinData, date)); 
    }
}

/*	This function calculates the previous date given a date string, taking into account the number of days in each month, leap years, and adjusting 
	the month and year if necessary. */
std::string pastDate( std::string date )
{
	//extracts the year, month, and day from the input date
    int year = atoi(date.substr(0, 4).c_str());
    int month = atoi(date.substr(5, 2).c_str());
    int day = atoi(date.substr(8, 2).c_str());

    if (day == 1)
    {
        if (month == 1) //if day == 1 and month == 1, new month is 12, decrements year
        {
            month = 12;
            year--;  
        }
		//If the month is 4, 6, 9, or 11 (April, June, September, or November), the function decrements the month by 1 and sets the day to 31.
        else if (month == 4 || month == 6 || month == 9 || month == 11)
        {
            month--;
            day = 31;
        }
		/* If the month is 3 (March), the function decrements the month by 1 and checks if the year is not divisible by 4 or if it is divisible by 100 
		   but not divisible by 400. This checks if the year is not a leap year. If it is not a leap year, the day is set to 28; 
		   otherwise, it is set to 29. */
		else if (month == 3)
        {
            month--;
            if (year % 4 != 0 || (year % 100 == 0 && year % 400 != 0))
                day = 28;
            else
                day = 29;
        }
		//For all other months, the function decrements the month by 1 and sets the day to 30.
        else
        {
            month--;
            day = 30;
        }
    }
	//If the day is not 1, the function simply decrements the day by 1
    else
        day--;
	/* The function then uses std::stringstream named str to construct the resulting date string in the format "YYYY-MM-DD". 
	   The std::setw and std::setfill manipulators are used to ensure leading zeros for single-digit month and day values. */
    std::stringstream str;
    str << std::setw(4) << std::setfill('0') << year << "-"
        << std::setw(2) << std::setfill('0') << month << "-"
        << std::setw(2) << std::setfill('0') << day;
	//The resulting date string is assigned back to the date variable.
    date = str.str();
    return (date);
}

/*	This function validates a date string by checking its length, format, and the individual components (year, month, and day) against specific ranges 
	and conditions to ensure it represents a valid date.
*/

bool ValidDate( const std::string &date )
{
    if (date.length() != 10)
        return false;
    if (date[4] != '-' || date[7] != '-')
        return false;

    int year = atoi(date.substr(0, 4).c_str());
    int month = atoi(date.substr(5, 2).c_str());
    int day = atoi(date.substr(8, 2).c_str());

    if (year < 2009 || year > 2023)
        return (false);
    if (month < 1 || month > 12)
        return (false);
    if (day < 1 || day > 31)
        return (false);
    if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
        return (false);
    if (month == 2)
    {
        if (day > 29)
            return (false);
		/* If the day is 29, it further checks if the year is not divisible by 4 or if it is divisible by 100 but not divisible by 400. 
		   These conditions check for leap years, where February 29 is valid. */
		if (day == 29 && (year % 4 != 0 || (year % 100 == 0 && year % 400 != 0)))
            return (false);
    }
    return (true);
}
