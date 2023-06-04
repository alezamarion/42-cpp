/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azamario <azamario@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 10:57:34 by azamario          #+#    #+#             */
/*   Updated: 2023/06/04 13:18:59 by azamario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main( void )
{

    Fixed a;
    Fixed const b( 10 );
    Fixed const c( 42.42f );
    Fixed const d( b );
    
    a = Fixed( 1234.4321f );
    
    std::cout << "\n" << "a is " << a << std::endl;
    std::cout << "b is " << b << std::endl;
    std::cout << "c is " << c << std::endl;
    std::cout << "d is " << d << "\n" << std::endl;
    
    std::cout << "a is " << a.toInt() << " \tas integer" << std::endl;
    std::cout << "b is " << b.toInt() << " \tas integer" << std::endl;
    std::cout << "c is " << c.toInt() << " \tas integer" << std::endl;
    std::cout << "d is " << d.toInt() << " \tas integer\n" << std::endl;

    std::cout << "a is " << a.toFloat() << " \tas float" << std::endl;
    std::cout << "b is " << b.toFloat() << " \tas float" << std::endl;
    std::cout << "c is " << c.toFloat() << " \tas float" << std::endl;
    std::cout << "d is " << d.toFloat() << " \tas float\n" << std::endl;
 
    return 0;
}