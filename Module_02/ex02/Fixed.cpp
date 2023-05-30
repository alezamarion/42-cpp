/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azamario <azamario@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 11:18:51 by azamario          #+#    #+#             */
/*   Updated: 2023/05/25 12:35:30 by azamario         ###   ########.fr       */
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

Fixed::Fixed(int const n)
{
    std::cout << "Int constructor called" << std::endl;
    this->_rawBits = n << _fractionalBits; // retorna o resulta do valor da casa decimal do parametro
	std::cout << "-----------rawBits:-------->>>>" << this->_rawBits << std::endl;
}

Fixed::Fixed(float const f)
{
    std::cout << "Float constructor called" << std::endl;
    this->_rawBits = static_cast<int>(roundf(f *(1 << _fractionalBits))); 
	std::cout << "-----------rawBits no float:-------->>>>" << this->_rawBits << std::endl;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
	return;
}

Fixed &Fixed::operator=(Fixed const &src)
{
	std::cout << "Copy assignment operator= called" << std::endl;
	this->setRawBits(src.getRawBits());
	return (*this);
}

bool Fixed::operator>(Fixed const &rhs) const
{
	std::cout << "operator> called" << std::endl;
	return (this->_rawBits > rhs.getRawBits());
}

bool Fixed::operator<(Fixed const &rhs) const
{
	std::cout << "operator< called" << std::endl;
	return (this->_rawBits < rhs.getRawBits());
}

bool Fixed::operator>=(Fixed const &rhs) const
{
	std::cout << "operator>= called" << std::endl;
	return (this->_rawBits >= rhs.getRawBits());
}

bool Fixed::operator<=(Fixed const &rhs) const
{
	std::cout << "operator<= called" << std::endl;
	return (this->_rawBits <= rhs.getRawBits());
}

bool Fixed::operator==(Fixed const &rhs) const
{
	std::cout << "operator== called" << std::endl;
	return (this->_rawBits == rhs.getRawBits());
}

bool Fixed::operator!=(Fixed const &rhs) const
{
	std::cout << "operator!= called" << std::endl;
	return (this->_rawBits != rhs.getRawBits());
}

Fixed Fixed::operator+(Fixed const &rhs)
{
	std::cout << "operator+ called" << std::endl;
	Fixed temp(this->toFloat() + rhs.toFloat());
	return (temp);
}

Fixed Fixed::operator-(Fixed const &rhs)
{
	std::cout << "operator- called" << std::endl;
	Fixed temp(this->toFloat() - rhs.toFloat());
	return (temp);
}

Fixed Fixed::operator*(Fixed const &rhs)
{
	std::cout << "operator* called" << std::endl;
	Fixed temp(this->toFloat() * rhs.toFloat());
	return (temp);
}

Fixed Fixed::operator/(Fixed const &rhs)
{
	std::cout << "operator/ called" << std::endl;
	Fixed temp(this->toFloat() / rhs.toFloat());
	return (temp);
}

Fixed &Fixed::operator++(void)
{
	std::cout << "++operator called" << std::endl;
	++this->_rawBits;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	std::cout << "operator++ called" << std::endl;
	Fixed temp = *this; // 1
	this->_rawBits++;   // 2
	return (temp);      // 1
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
	std::cout << "&Fixed::max member function called" << std::endl;
	if(lhs.getRawBits() > rhs.getRawBits())
		return (lhs);						
	else
		return(rhs);						
}

Fixed const &Fixed::max(Fixed const &lhs, Fixed const &rhs)
{
	std::cout << "const &Fixed::max member function called" << std::endl;
	if(lhs.getRawBits() > rhs.getRawBits())
		return (lhs);
	else
		return(rhs);
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return(this->_rawBits);
}

void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->_rawBits = raw;
	return;
}

int Fixed::toInt(void) const
{
	std::cout << "toInt member function called" << std::endl;
    return (this->_rawBits >> _fractionalBits);
}

float Fixed::toFloat(void) const
{
	std::cout << "toFloat member function called" << std::endl;
    return (static_cast<float>(this->_rawBits) / (1 << _fractionalBits));
}

std::ostream &operator<<(std::ostream &output_stream, Fixed const &fixed_number)
{
	std::cout << "&operator<< friend function called" << std::endl;
	output_stream << fixed_number.toFloat();
	return(output_stream);
}
