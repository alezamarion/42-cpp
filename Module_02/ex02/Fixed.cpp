/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azamario <azamario@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 11:18:51 by azamario          #+#    #+#             */
/*   Updated: 2023/06/04 13:20:07 by azamario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int const Fixed::_fractionalBits = 8;

Fixed::Fixed(void) : _rawBits(0)
{	
	return;
}

Fixed::Fixed(Fixed const &src) 
{	
	*this = src;
	return;
}

Fixed::Fixed(int const n)
{    
	this->_rawBits = n << _fractionalBits;
}

Fixed::Fixed(float const f)
{    
	this->_rawBits = static_cast<int>(roundf(f *(1 << _fractionalBits))); 
}

Fixed::~Fixed(void)
{
	return;
}

Fixed &Fixed::operator=(Fixed const &src)
{
	this->setRawBits(src.getRawBits());
	return (*this);
}

bool Fixed::operator>(Fixed const &rhs) const
{
	return (this->_rawBits > rhs.getRawBits());
}

bool Fixed::operator<(Fixed const &rhs) const
{
	return (this->_rawBits < rhs.getRawBits());
}

bool Fixed::operator>=(Fixed const &rhs) const
{
	return (this->_rawBits >= rhs.getRawBits());
}

bool Fixed::operator<=(Fixed const &rhs) const
{
	return (this->_rawBits <= rhs.getRawBits());
}

bool Fixed::operator==(Fixed const &rhs) const
{
	return (this->_rawBits == rhs.getRawBits());
}

bool Fixed::operator!=(Fixed const &rhs) const
{
	return (this->_rawBits != rhs.getRawBits());
}

Fixed Fixed::operator+(Fixed const &rhs)
{
	Fixed temp(this->toFloat() + rhs.toFloat());
	return (temp);
}

Fixed Fixed::operator-(Fixed const &rhs)
{
	Fixed temp(this->toFloat() - rhs.toFloat());
	return (temp);
}

Fixed Fixed::operator*(Fixed const &rhs)
{
	Fixed temp(this->toFloat() * rhs.toFloat());
	return (temp);
}

Fixed Fixed::operator/(Fixed const &rhs)
{
	Fixed temp(this->toFloat() / rhs.toFloat());
	return (temp);
}

Fixed &Fixed::operator++(void)
{
	++this->_rawBits;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed temp = *this;
	this->_rawBits++;
	return (temp);
}

Fixed &Fixed::operator--(void)
{
	--this->_rawBits;
	return (*this);
}

Fixed Fixed::operator--(int)
{
	Fixed temp = *this;
	this->_rawBits--;
	return (temp);
}

Fixed &Fixed::min(Fixed &lhs, Fixed &rhs)
{
	if(lhs.getRawBits() > rhs.getRawBits())
		return (rhs);						
	else
		return(lhs);						
}

Fixed const &Fixed::min(Fixed const &lhs, Fixed const &rhs)
{
	if(lhs.getRawBits() > rhs.getRawBits())
		return (rhs);						
	else
		return(lhs);						
}

Fixed &Fixed::max(Fixed &lhs, Fixed &rhs)
{
	if(lhs.getRawBits() > rhs.getRawBits())
		return (lhs);						
	else
		return(rhs);						
}

Fixed const &Fixed::max(Fixed const &lhs, Fixed const &rhs)
{
	if(lhs.getRawBits() > rhs.getRawBits())
		return (lhs);
	else
		return(rhs);
}

int Fixed::getRawBits(void) const
{
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
