/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azamario <azamario@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 00:24:24 by azamario          #+#    #+#             */
/*   Updated: 2023/06/14 23:57:14 by azamario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int argc, char *argv[])
{
	if (argc != 2)
  	{
    	std::cout << "\nUsage: ./ScalarConverter <stringToConvert>\n" << std::endl;

	    return (1);
  	}
  	std::cout << std::endl;

	ScalarConverter::convert(argv[1]);

  	std::cout << std::endl;
	return (0);
}
