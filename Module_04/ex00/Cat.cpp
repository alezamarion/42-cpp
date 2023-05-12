/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azamario <azamario@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 12:37:08 by azamario          #+#    #+#             */
/*   Updated: 2023/05/12 12:49:09 by azamario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void) : Animal("Cat")
{
    std::cout << "Cat Default Constructor called\n";
}

Cat::Cat(Cat const &src) : Animal("Cat")
{
    std::cout << "Cat Copy Constructor called\n";
	*this = src;
}
Cat::~Cat(void)
{
    std::cout << "Cat Destructor called\n";
}

Cat &Cat::operator=(Cat const &rhs)
{
    std::cout << "Cat Assingment Operator called\n";
    this->_type = rhs.getType();
    return (*this);
}

void Cat::makeSound(void) const
{
    std::cout <<"Meow! 🐈\n";
}
