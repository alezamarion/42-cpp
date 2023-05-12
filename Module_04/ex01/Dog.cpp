/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azamario <azamario@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 12:40:24 by azamario          #+#    #+#             */
/*   Updated: 2023/05/12 13:14:00 by azamario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

#include "Dog.hpp"

Dog::Dog(void) : Animal("Dog")
{
    std::cout << "Dog Default Constructor called\n";
    this->_brain = new Brain();
}

Dog::Dog(Dog const &src) : Animal("Dog")
{
    std::cout << "Dog Copy Constuctor called\n";
    this->_brain = new Brain (*src.getBrain());
    *this = src;
}

Dog::~Dog()
{
    std::cout << "Dog Destructor called\n";
    delete this->_brain;
}

Dog &Dog::operator=(Dog const &rhs)
{
    std::cout << "Dog Assingment Operator called\n";
    this->_type = rhs.getType();
    *this->_brain = *rhs.getBrain();
    return(*this);
}

Brain const *Dog::getBrain(void) const
{
    return(this->_brain);
}

void Dog::makeSound(void) const
{
    std::cout << "Aauuuuu 🐕\n";
}
