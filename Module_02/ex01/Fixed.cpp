/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azamario <azamario@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 11:04:03 by azamario          #+#    #+#             */
/*   Updated: 2023/05/25 12:25:52 by azamario         ###   ########.fr       */
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

/* Constructor converts an integer to the corresponding fixed-point value 
	It performs a bitwise left shift operation (<<) on the n value by _fractionalBits number of bits.
	The purpose of this bitwise shift operation is to convert the n value from an integer representation to a 
	fixed-point representation, where _fractionalBits represents the number of fractional bits used for representing 
	the decimal portion of the value. By shifting the bits to the left, the integer value is effectively multiplied 
	by 2 raised to the power of _fractionalBits.
	For example, if _fractionalBits is 8 and n is 5, the line this->_rawBits = n << _fractionalBits; would set 
	_rawBits to 1280 (binary: 00000101 shifted left by 8 bits becomes 10100000000). */
	
Fixed::Fixed(int const n)
{
    std::cout << "Int constructor called" << std::endl;
    this->_rawBits = n << _fractionalBits;
}

/* This code constructs an object of the Fixed class with a float input, scaling and rounding the input value to fit a 
	fixed-point representation stored in the _rawBits member variable.
	a. 1 << _fractionalBits: This shifts the value 1 to the left by _fractionalBits number of bits.
		The _fractionalBits represents the number of fractional bits in the fixed-point representation.
	b. f * (1 << _fractionalBits): This multiplies the float value f by the value obtained from step (a).
		It scales the float value to fit the desired fixed-point representation.
	c. roundf(f * (1 << _fractionalBits)): This rounds the scaled value obtained from step (b) to the nearest integer.
	d. static_cast<int>(roundf(f * (1 << _fractionalBits))): This casts the rounded value to an int type.
		It discards any decimal portion of the value, as the _rawBits variable is assumed to be of integer type.
	e. this->_rawBits = ...: This assigns the resulting integer value to the _rawBits member variable of the Fixed class */
Fixed::Fixed(float const f)
{
    std::cout << "Float constructor called" << std::endl;
    this->_rawBits = static_cast<int>(roundf(f *(1 << _fractionalBits)));
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
	return;
}

Fixed &Fixed::operator=(Fixed const &src)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->setRawBits(src.getRawBits());
	return (*this);
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return(this->_rawBits);
}

void Fixed::setRawBits(int const raw)
{
	this->_rawBits = raw;
	return;
}

int Fixed::toInt(void) const
{
    return (this->_rawBits >> _fractionalBits);
}

float Fixed::toFloat(void) const
{
    return (static_cast<float>(this->_rawBits) / (1 << _fractionalBits));
}

std::ostream &operator<<(std::ostream &output_stream, Fixed const &fixed_number)
{
	output_stream << fixed_number.toFloat();
	return(output_stream);
}
