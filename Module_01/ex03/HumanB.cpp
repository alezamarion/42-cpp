/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azamario <azamario@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 17:35:59 by azamario          #+#    #+#             */
/*   Updated: 2023/05/07 17:38:56 by azamario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name), _weapon(NULL)
{
    return;
}

void HumanB::attack(void) const
{
    std::cout << this->_name << " attacks with their " << this->_weapon->getType() << std::endl; 
}

void HumanB::setWeapon(Weapon &weapon)
{
    this->_weapon = &weapon;
}
