/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azamario <azamario@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 21:06:47 by azamario          #+#    #+#             */
/*   Updated: 2023/06/26 12:17:53 by azamario         ###   ########.fr       */
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
	if (fileIn.peek() == std::ifstream::traits_type::eof())
	{
        std::cout << "\nThe file is empty.\n" << std::endl;
		return (false);
    } 
	return(true);
}

bool fileOutValidation(std::ofstream &fileOut, char *file)
{
	std::string fileReplace = std::string(file) + ".replace"; 
	fileOut.open(fileReplace.c_str());
	if(fileOut.fail())
	{
		std::cerr << "Failed to create: " << fileReplace << std::endl;
		return (false);
	} 
	return (true);
}

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
		content << fileIn.rdbuf(); 
	
		fileOut << replace(content.str(), argv[2] ,argv[3]);
	
		fileIn.close();
		fileOut.close();

		std::cout << "\nSuccessful replacement! Check file.txt.replace\n" << std::endl;
 	}
	else
		return(1);
    return (0);
}
