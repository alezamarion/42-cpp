/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azamario <azamario@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 12:10:31 by azamario          #+#    #+#             */
/*   Updated: 2023/05/12 12:29:01 by azamario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void) : _type("Animal")
{
	std::cout << "Animal default Constructor called\n";
}

Animal::Animal(std::string const type) : _type(type)
{
    std::cout << "Animal parametric constructor called\n";
}

Animal::Animal(Animal const &src)
{
	std::cout << "Animal copy constructor called\n";
    *this = src;
}

Animal::~Animal(void)
{
	std::cout << "Animal destructor called\n";
}
        
Animal &Animal::operator=(Animal const &rhs)
{
    std::cout << "Animal assignment operator called\n";
	this->_type = rhs.getType();;
	return (*this);
}
        
std::string const Animal::getType(void) const
{
    return (this->_type);
}

void Animal::setType(std::string const type)
{
    this->_type = type;
}

void Animal::makeSound(void) const
{
    std::cout << "🐾\n";
}

std::ostream &operator <<(std::ostream &out, Animal const &in)
{
	out << in.getType();
	return (out);
}
