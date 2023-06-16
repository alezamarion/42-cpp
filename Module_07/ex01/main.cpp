/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azamario <azamario@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 17:49:26 by azamario          #+#    #+#             */
/*   Updated: 2023/06/16 08:56:39 by azamario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Iter.hpp"

int main( void )
{
	{
		int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
		int length = sizeof(array) / sizeof(array[0]);

		std::cout << std::endl << "Int   array: ";

    	// explicit instantiation -> preferred
		iter(array, length, printArray<int>); 

		std::cout << std::endl;
	}

	{
		float array[] = {1.4, 3.2, 5.9, 7.8, 9, 10};
		int length = sizeof(array) / sizeof(array[0]);

		std::cout << std::endl << "Float array: ";

    	// implicit instantiation -> it might not work for complex classes
		iter(array, length, printArray); 

  		std::cout << std::endl;
	}

	{
		char array[] = {'z', 'e', 'g', 'r', 't', 'u', 'y', 'l', 'a', 'q', 'i'};
		int length = sizeof(array) / sizeof(array[0]);

		std::cout << std::endl << "Char  array: ";

		iter(array, length, printArray<char>);

  		std::cout << std::endl << std::endl;
	}

    return (0);
}
