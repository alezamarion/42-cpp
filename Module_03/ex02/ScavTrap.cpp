/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azamario <azamario@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 21:30:38 by azamario          #+#    #+#             */
/*   Updated: 2023/06/05 13:50:23 by azamario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) : ClapTrap()
{
    std::cout << "ScavTrap default constructor called" << std::endl;
    this->setName("ScavTrap");
    this->setClassName("ScavTrap");
	this->setHP(100);
    this->setEP(50);
    this->setAD(20);
    return;    
}

ScavTrap::ScavTrap(std::string const name) : ClapTrap(name)
{
    std::cout << "ScavTrap parametric constructor called" << std::endl;
    this->setClassName("ScavTrap");
	this->setHP(100);
    this->setEP(50);
    this->setAD(20);
    return;    
}

ScavTrap::ScavTrap(ScavTrap const &src) : ClapTrap()
{
    std::cout << "ScavTrap copy constructor called" << std::endl;
    *this = src;
    return;
}

ScavTrap::~ScavTrap(void)
{
    std::cout << "ScavTrap destructor called" << std::endl;
    return;
}
        
ScavTrap &ScavTrap::operator=(ScavTrap const &rhs)
{
    std::cout << "ScavTrap copy assignment called" << std::endl;
    const_cast<std::string &> (this->_name) = rhs.getName();
    this->_hitPoint = rhs.getHP();
    this->_energyPoint = rhs.getEP();
    this->_attackDamage = rhs.getAD();
    return (*this);    
}

void ScavTrap::attack(const std::string& target)
{
    if (this->getHP() == 0)
    {
        std::cout << this->getClassName() << " " << this->getName()
                  << " is dead!. He cannot not attack"
                  << target << std::endl;
        return;
    }
    if (this->getEP() == 0)
    {
        std::cout << "No energy remainig!"
                  << this->getClassName() << " " << this->getName()
                  << " cannot attacks!" << target << std::endl;
        return;
    }
    std::cout << this->getClassName() << " " << this->getName()
              << " attacks " << target
              << " causing " << this->getAD() 
              << "points of damage!" << std::endl;
    this->_energyPoint--;   
}

void ScavTrap::guardGate(void) const
{
    if (this->getHP() == 0)
    {
        std::cout << "ScavTrap " << this->getName() << " is dead!. He cannot enter in Gate Keeper mode" << std::endl;
        return;
    }
    std::cout << "ScavTrap " << this->getName() << " is now Gate Keeper mode" << std::endl;    
}
