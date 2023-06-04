/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azamario <azamario@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 10:41:05 by azamario          #+#    #+#             */
/*   Updated: 2023/06/04 12:38:15 by azamario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int const Fixed::_fractionalBits = 8;

Fixed::Fixed(void) : _rawBits(0)
{
    std::cout << "Default Constructor called" << std::endl;
    return;
}

Fixed::Fixed(Fixed const &src)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = src;
    return;
}

Fixed::~Fixed(void)
{
    std::cout << "Destructor called" << std::endl;
    return;
}

/* The given function is an overloaded assignment operator function for the class Fixed.
    It allows you to assign one Fixed object to another Fixed object. 
*/    
Fixed &Fixed::operator=(Fixed const &src)
{
    std::cout << "Copy assignment operator called" << std::endl;

    /* This line calls the member function getRawBits() on the src object to retrieve the raw value (bits) of src.
       The retrieved raw value is then passed to the member function setRawBits() of the current object (this), 
       setting its raw bits to the same value as src.
       Essentially, this line copies the raw bits from the source object to the current object, performing a bitwise copy.
    */
    this->setRawBits(src.getRawBits());
    return *this;
}
        
int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return (this->_rawBits);
}

void Fixed::setRawBits(int const raw)
{
    this->_rawBits = raw;
    return;
}
