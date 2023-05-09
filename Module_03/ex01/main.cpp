/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azamario <azamario@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 21:41:45 by azamario          #+#    #+#             */
/*   Updated: 2023/05/08 21:42:15 by azamario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
    ClapTrap clapTrap("Megazord");
    ScavTrap scavTrap("Daimon");
  
    std::cout << "\n";
    std::cout << clapTrap << "\n";
    std::cout << scavTrap << "\n";

    clapTrap.attack(scavTrap.getName());
    scavTrap.takeDamage(clapTrap.getAD());
    scavTrap.guardGate();
    scavTrap.beRepaired(1);
    std::cout << "\n";

    scavTrap.attack(clapTrap.getName());
    clapTrap.takeDamage(scavTrap.getAD());
    scavTrap.guardGate();
    scavTrap.beRepaired(1);
    std::cout << "\n";

    std::cout << clapTrap << "\n";
    std::cout << scavTrap << "\n";

    return (0);
}