/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azamario <azamario@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 16:33:35 by azamario          #+#    #+#             */
/*   Updated: 2023/06/01 20:08:57 by azamario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void Zombie::announce(void)
{
    std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(std::string name)
{
   this->_name = name;
}

Zombie::Zombie(void)
{
    return;
}

Zombie::~Zombie(void)
{
    std::cout << _name << " Arghhhh \033[0;31mdead :(\033[0m" << std::endl;
}
