/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azamario <azamario@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 17:49:26 by azamario          #+#    #+#             */
/*   Updated: 2023/06/16 09:11:04 by azamario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Iter.hpp"

int main( void )
{
	/*	The sizeof operator is used to determine the size, in bytes, of a particular type or object. 
		In this case, sizeof(array) returns the total size occupied by the array in bytes.
		The sizeof(array[0]) returns the size of an individual element in the array. Since array is an array of integers, 
		sizeof(array[0]) returns the size of an int in bytes.
		By dividing the total size of the array (sizeof(array)) by the size of a single element (sizeof(array[0])), 
		you get the number of elements in the array. This value is then assigned to the variable length.
	*/
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
