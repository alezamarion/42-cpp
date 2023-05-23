/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azamario <azamario@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 21:06:47 by azamario          #+#    #+#             */
/*   Updated: 2023/05/23 17:58:43 by azamario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "strReplace.hpp"
#include <iostream>

bool fileInValidation(std::ifstream &fileIn, char *file)
{
	fileIn.open(file);
	if (fileIn.fail())
	{
		std::cerr << "Failed to open: " << file << std::endl;
		return (false);
	}
	return(true);
}

/*
	fileOutValidation takes an std::ofstream object and a character array representing a filename. 
	It appends ".replace" to the filename and opens a file with that modified filename for writing. 
	If the file opening operation succeeds, it returns true; otherwise, it returns false.
*/

bool fileOutValidation(std::ofstream &fileOut, char *file)
{
	//This creates a new string that represents the desired filename for the output file.
	std::string fileReplace = std::string(file) + ".replace"; 
	//Opens the file with the specified filename for writing. The c_str() function is used to convert the std::string object fileReplace
	//into a C-style string (a null-terminated character array) required by the open function
	fileOut.open(fileReplace.c_str());
	if(fileOut.fail())
	{
		std::cerr << "Failed to create: " << fileReplace << std::endl;
		return (false);
	} 
	return (true);
}

/*
    argc_1 = ./exe
    argc_2 = argv[1] file a ser lido " Hello Jorge como vai"
    argc_3 = argv[2] s1 com o texto para ser procurado    " Hello Jorge"
    argc_4 = argv[3] s2 com o texto será substituir o s1  " Ola alexandre"
    fileout = Ola alexandre como vai

	main() reads command-line arguments representing input and output file names,
	performs input and output file validations, reads the contents of the input file, 
	replaces a specified substring in the content, and writes the modified content to the output file. 
	If any errors occur during the process, appropriate error messages are printed, and the program returns
	a non-zero value.
*/

int main(int argc, char *argv[])
{
    std::ifstream fileIn;
	std::ifstream fileInCheck;
    std::ofstream fileOut;
	std::ofstream fileOutCheck;
    std::stringstream content;

    if (argc != 4)
    {
        std::cerr << "Invalid number of arguments" << std::endl;
        return (1);
    }
    else if (fileInValidation(fileIn, argv[1]) && fileOutValidation(fileOut, argv[1]))
	{		
		//Extracts the contents of the input file and inserts them into the string stream.
		content << fileIn.rdbuf(); 
	
		/* The replace function is called with three arguments: the contents of content.str()
		(the string representation of the content), argv[2] (the string to be replaced), and argv[3]
		(the string to replace with). The result of the replace function is written to the fileOut stream
		using fileOut << replace(content.str(), argv[2], argv[3]);.*/	
		fileOut << replace(content.str(), argv[2] ,argv[3]);
	
		fileIn.close();
		fileOut.close();

		std::cout << "\nSuccessful replacement! Check file.txt.replace\n" << std::endl;
 	}
	else
		return(1);
    return (0);
}
