/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azamario <azamario@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 14:28:20 by azamario          #+#    #+#             */
/*   Updated: 2023/05/12 14:28:24 by azamario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void) : AAnimal("Cat")
{
    std::cout << "Cat Default Constructor called\n";
    this->_brain = new Brain();
}

Cat::Cat(Cat const &src) : AAnimal("Cat")
{
    std::cout << "Cat Copy Constructor called\n";
    this->_brain = new Brain(*src.getBrain());
	*this = src;
}
Cat::~Cat(void)
{
    std::cout << "Cat Destructor called\n";
    delete this->_brain;
}

Cat &Cat::operator=(Cat const &rhs)
{
    std::cout << "Cat Assingment Operator called\n";
    this->_type = rhs.getType();
    *this->_brain = *rhs.getBrain();
    return (*this);
}

Brain const *Cat::getBrain(void) const
{
    return (this->_brain);
}

void Cat::makeSound(void) const
{
    std::cout <<"Meauuu 🐈\n";
}
