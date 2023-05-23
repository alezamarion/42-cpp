/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azamario <azamario@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 15:54:26 by azamario          #+#    #+#             */
/*   Updated: 2023/05/22 22:09:28 by azamario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string name)
{
   this->_name = name;
}

Zombie::~Zombie(void)
{
    std::cout << _name << " Arghhhh \033[0;31mdead :(\033[0m\n" << std::endl;
}

void Zombie::announce(void)
{
    std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie* newZombie(std::string name)
{
    return new Zombie(name);
}

void randomChump(std::string _name)
{
    Zombie z(_name);
    z.announce();
}
