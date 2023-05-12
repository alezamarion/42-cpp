/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azamario <azamario@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 12:54:09 by azamario          #+#    #+#             */
/*   Updated: 2023/05/12 12:54:38 by azamario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat")
{
    std::cout << "WrongCat Default Constructor called\n";
}

WrongCat::WrongCat(WrongCat const &src) : WrongAnimal("WrongCat")
{
    std::cout << "WrongCat Copy Constructor called\n";
    *this = src;
}

WrongCat::~WrongCat()
{
    std::cout << "WrongCat Destructor called\n";
}

WrongCat &WrongCat::operator=(WrongCat const &rhs)
{
    std::cout << "WrongCat Assigment Operator called\n";
    this->_type = rhs.getType();
    return(*this);
}

void WrongCat::makeSound(void) const
{
    std::cout << "WrongCat ❌\n";
}
