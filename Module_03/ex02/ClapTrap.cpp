/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azamario <azamario@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 21:25:04 by azamario          #+#    #+#             */
/*   Updated: 2023/06/05 13:47:51 by azamario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void): _name("ClapTrap"), _className("ClapTrap"), _hitPoint(10), _energyPoint(10), _attackDamage(0)
{
    std::cout << "Default constructor called" << std::endl;
    return;
}

ClapTrap::ClapTrap(std::string const name) :_name(name), _className("ClapTrap"), _hitPoint(10), _energyPoint(10), _attackDamage(0)
{
    std::cout << "ClapTrap parametric constructor called" << std::endl;
    return;
}

ClapTrap::ClapTrap(ClapTrap const &src)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = src;
    return;
}

ClapTrap::~ClapTrap(void)
{
    std::cout << "ClapTrap Destructor called" << std::endl;
    return;
}

ClapTrap &ClapTrap::operator=(ClapTrap const &rhs)
{
    std::cout << "Copy assignment operator called" << std::endl;
    const_cast<std::string &> (this->_name) = rhs.getName();
    this->_hitPoint = rhs.getHP();
    this->_energyPoint = rhs.getEP();
    this->_attackDamage = rhs.getAD();
    return (*this);    
}
        
std::string ClapTrap::getName(void) const
{
    return (this->_name);
}

std::string ClapTrap::getClassName(void) const
{
	return (this->_className);
}

unsigned int ClapTrap::getHP(void) const
{
    return (this->_hitPoint);
}

unsigned int ClapTrap::getEP(void) const
{
    return (this->_energyPoint);
}

unsigned int ClapTrap::getAD(void) const
{
    return (this->_attackDamage);
}

void ClapTrap::setName(std::string const &name)
{
    const_cast<std::string &>(this->_name) = name;
}

void ClapTrap::setClassName(std::string const &className)
{
	const_cast<std::string &>(this->_className) = className;
}

void ClapTrap::setHP(unsigned int hitPoints)
{
    this->_hitPoint = hitPoints;   
}
void ClapTrap::setEP(unsigned int energyPoints)
{
    this->_energyPoint = energyPoints;
}

void ClapTrap::setAD(unsigned int attackDamage)
{
    this->_attackDamage = attackDamage;
}

void ClapTrap::attack(const std::string& target)
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

void ClapTrap::takeDamage(unsigned int amount)
{
    if (this->getHP() == 0)
    {
        std::cout << this->getClassName() << " " << this->getName()
                  << " is dead!. He cannot suffer damage" << std::endl;
        return;
    }
    std::cout << this->getClassName() << " " << this->getName()
              << " suffered " << amount << " points of damage!\n";
    if (this->_hitPoint <= amount)
        this->_hitPoint = 0;
    else 
        this->_hitPoint -= amount;
    if (this->getHP() <= 0)
    {
        std::cout << this->getClassName() << " " << this->getName()
                  << " has died!" << std::endl;   
    }  
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (this->getHP() == 0)
    {
        std::cout << this->getClassName() << " " << this->getName()
                  << " is dead!. He cannot be repaired" << std::endl;
        return;
    }
    if (this->getEP() == 0)
    {
        std::cout << "No energy remainig!"
                  << this->getClassName() << " " << this->getName()
                  << " cannot be repaired!" <<std::endl;
        return;
    }
    std::cout << this->getClassName() << " " << this->getName()
              << " recovered " << amount
              << " points of hit points!\n";
    if (this->_hitPoint + amount > 10)
        this->_hitPoint = 10;
    else
        this->_hitPoint += amount;
    this->_energyPoint--; 
}
            
std::ostream &operator<<(std::ostream &out, ClapTrap const &in)
{
    out << "Class: " << in.getClassName() << "\n";
    out << "Name: "  << in.getName() << "\n";
    out << "HP: "    << in.getHP() << "\n";
    out << "EP: "    << in.getEP() << "\n";
    out << "AD: "    << in.getAD() << "\n";
    return (out); 
}
