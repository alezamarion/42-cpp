/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azamario <azamario@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 20:29:29 by azamario          #+#    #+#             */
/*   Updated: 2023/05/25 12:44:25 by azamario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void): _name("ClapTrap"), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
    std::cout << "Default constructor called" << std::endl;
    return;
}

ClapTrap::ClapTrap(std::string const name) :_name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
    std::cout << "Parametric constructor called" << std::endl;
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
    std::cout << "Destructor called" << std::endl;
    return;
}

ClapTrap &ClapTrap::operator=(ClapTrap const &rhs)
{
    std::cout << "Copy assignment operator called" << std::endl;
    const_cast<std::string &> (this->_name) = rhs.getName();
    this->_hitPoints = rhs.getHP();
    this->_energyPoints = rhs.getEP();
    this->_attackDamage = rhs.getAD();
    return (*this);    
}
        
std::string ClapTrap::getName(void) const
{
    return (this->_name);
}

unsigned int ClapTrap::getHP(void) const
{
    return (this->_hitPoints);
}

unsigned int ClapTrap::getEP(void) const
{
    return (this->_energyPoints);
}

unsigned int ClapTrap::getAD(void) const
{
    return (this->_attackDamage);
}

void ClapTrap::setName(std::string const &name)
{
    const_cast<std::string &>(this->_name) = name;
}

void ClapTrap::setHP(unsigned int hitPoints)
{
    this->_hitPoints = hitPoints;   
}
void ClapTrap::setEP(unsigned int energyPoints)
{
    this->_energyPoints = energyPoints;
}

void ClapTrap::setAD(unsigned int attackDamage)
{
    this->_attackDamage = attackDamage;
}

void ClapTrap::attack(const std::string& target)
{
    if (this->getHP() == 0)
    {
        std::cout << "ClapTrap " << this->getName()
                  << " is dead!. He cannot not attack"
                  << target << std::endl;
        return;
    }
    if (this->getEP() == 0)
    {
        std::cout << "No energy remainig!"
                  << "ClapTrap " << this->getName()
                  << " cannot attacks!" << target << std::endl;
        return;
    }
    std::cout << "ClapTrap " << this->getName()
              << " attacks " << target
              << " causing " << this->getAD() 
              << "points of damage!" << std::endl;
    this->_energyPoints--;   
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (this->getHP() == 0)
    {
         std::cout << "ClapTrap " << this->getName()
                  << " is dead!. He cannot suffer damage" << std::endl;
        return;
    }
    std::cout << "ClapTrap "
            << this->getName()
            << " suffered "
            << amount << " points of damage!\n";
    if (this->_hitPoints <= amount)
        this->_hitPoints = 0;
    else 
        this->_hitPoints -= amount;
    if(this->getHP() <= 0)
    {
        std::cout << "ClapTrap " << this->getName()
                  << " has died!" << std::endl;   
    }  
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if(this->getHP() == 0)
    {
         std::cout << "ClapTrap " << this->getName()
                  << " is dead!. He cannot be repaired" << std::endl;
        return;
    }
    if(this->getEP() == 0)
    {
         std::cout << "No energy remainig!"
                  << "ClapTrap " << this->getName()
                  << " cannot be repaired!" <<std::endl;
        return;
    }
    std::cout << "ClapTrap " << this->getName()
              << " recovered " << amount
              << " points of hit points!\n";
    if (this->_hitPoints + amount > 10)
        this->_hitPoints = 10;
    else
        this->_hitPoints += amount;
    this->_energyPoints--; 
}
            
std::ostream &operator<<(std::ostream &out, ClapTrap const &in)
{
    out << "Name: " << in.getName() << "\n";
    out << "HP: " << in.getHP() << "\n";
    out << "EP: " << in.getEP() << "\n";
    out << "AD: " << in.getAD() << "\n";
    return (out); 
}
