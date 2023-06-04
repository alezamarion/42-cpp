/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azamario <azamario@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 11:22:12 by azamario          #+#    #+#             */
/*   Updated: 2023/06/04 13:20:57 by azamario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main(void) 
{
    Fixed a;
    Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;

    std::cout << b << std::endl;
    std::cout << Fixed::max( a, b ) << std::endl;

	std::cout << "\n";
	
    std::cout << "a: " << a << std::endl;
    std::cout << "b: " << b << std::endl;

    if (a < b)
		std::cout << "a < b\n";
    if (a <= b)
		std::cout << "a <= b\n";
    if (a != b)
		std::cout << "a != b\n";

	std::cout << "\n";

    std::cout << "a + b:  " << a + b << std::endl;
    std::cout << "a - b:  " << a - b << std::endl;
    std::cout << "a * b:  " << a * b << std::endl;
    std::cout << "a / b:  " << a / b << std::endl;

	std::cout << "\n";
		
    return 0;
}
