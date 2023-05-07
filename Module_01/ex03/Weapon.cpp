/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azamario <azamario@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 17:16:44 by azamario          #+#    #+#             */
/*   Updated: 2023/05/07 17:22:05 by azamario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type)
{
    _type = type;
}

const std::string &Weapon::getType(void) const
{
    return (this->_type);
}

void Weapon::setType(std::string type)
{
    this->_type = type;
}
