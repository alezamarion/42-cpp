/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azamario <azamario@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 11:04:03 by azamario          #+#    #+#             */
/*   Updated: 2023/06/04 13:13:42 by azamario         ###   ########.fr       */
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
	the decimal portion of the value. */
	
Fixed::Fixed(int const n)
{
    std::cout << "Int constructor called" << std::endl;
    /* The purpose of this operation is to convert the int value n into the fixed-point representation by shifting it 
		to the left by _fractionalBits positions. It performs a bitwise left shift operation on the n value. 
		Shifting n to the left by _fractionalBits positions effectively multiplies n by 2^_fractionalBits. 
	*/
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

/* Used to convert a fixed-point value back to its corresponding integer representation.
   In binary representation, shifting a number to the right by one position is equivalent to dividing it by 2. 
   Similarly, shifting it by _fractionalBits positions is equivalent to dividing it by 2^_fractionalBits. 
   By performing this right shift operation, the code effectively scales down the fixed-point value to obtain the 
   	corresponding integer value. 
*/
int Fixed::toInt(void) const
{
    return (this->_rawBits >> _fractionalBits);
}

/* Converts a fixed-point value to its floating-point representation by dividing the internal representation of the value 
	by the appropriate scale factor. This allows for obtaining the corresponding floating-point value from a fixed-point value.
   - this->_rawBits represents the internal storage of the fixed-point value in the Fixed class. It contains both the integer 
   		and fractional parts of the value. The _fractionalBits variable determines the position of the binary point, indicating 
		the number of bits allocated for the fractional part.
   - The expression static_cast<float>(this->_rawBits) converts the _rawBits value to a float type. This is done to ensure that 
   		the division operation that follows is performed using floating-point arithmetic rather than integer arithmetic.
   - The line (1 << _fractionalBits) calculates 2^_fractionalBits, which corresponds to shifting the value 1 left by _fractionalBits positions. 
   		This effectively represents the scale factor required to convert the fixed-point value to a floating-point value.
   - Finally, the expression (static_cast<float>(this->_rawBits) / (1 << _fractionalBits)) divides the converted _rawBits value by the scale factor. 
   		This division operation results in the floating-point representation of the fixed-point value. The division is performed using floating-point 
		arithmetic, allowing for the fractional part of the fixed-point value to be accurately represented in the resulting float value.
*/
float Fixed::toFloat(void) const
{
    return (static_cast<float>(this->_rawBits) / (1 << _fractionalBits));
}

std::ostream &operator<<(std::ostream &output_stream, Fixed const &fixed_number)
{
	output_stream << fixed_number.toFloat();
	return(output_stream);
}
