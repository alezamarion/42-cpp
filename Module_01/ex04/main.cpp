/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azamario <azamario@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 21:06:47 by azamario          #+#    #+#             */
/*   Updated: 2023/05/07 21:08:05 by azamario         ###   ########.fr       */
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

bool fileOutValidation(std::ofstream &fileOut, char *file)
{
	std::string fileReplace = std::string(file) + ".replace";
	fileOut.open(fileReplace.c_str()); // c_str ????
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
*/

int main(int argc, char *argv[])
{
    std::ifstream fileIn;  // Abrir o arquivo, procurar o s1 e trocar pelo s2 e salvar em file out
    std::ofstream fileOut;
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
	}
	else
		return(1);
    return (0);
}
