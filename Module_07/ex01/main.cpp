/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azamario <azamario@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 17:49:26 by azamario          #+#    #+#             */
/*   Updated: 2023/05/16 20:30:42 by azamario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Iter.hpp"

/*

int main(void)
{
    int arr[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    char arr2[10] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j'};
    float arr3[10] = {0.0f, 0.1f, 0.2f, 0.3f, 0.4f, 0.5f, 0.6f, 0.7f, 0.8f, 0.9f};

    std::cout << "[ INT ARRAY ]\n";
    iter(arr, 10, printArray);
    std::cout << "\n";

    std::cout << "\n";

    std::cout << "[ CHAR ARRAY ]\n";
    iter(arr2, 10, printArray);
    std::cout << "\n";

    std::cout << "\n";

    std::cout << "[ FLOAT ARRAY ]\n";
    iter(arr3, 10, printArray);
    std::cout << "\n";

    return (0);
}

*/

int main( void )
{

	{
		int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
		int length = sizeof(array) / sizeof(array[0]);

		std::cout << std::endl << "Int   array: ";

		iter(array, length, printArray<int>);

		std::cout << std::endl;
	}

	{
		float array[] = {1.4, 3.2, 5.9, 7.8, 9, 10};
		int length = sizeof(array) / sizeof(array[0]);

		std::cout << std::endl << "Float array: ";

		iter(array, length, printArray<float>);

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