/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azamario <azamario@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 13:53:48 by azamario          #+#    #+#             */
/*   Updated: 2023/05/09 13:54:58 by azamario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "FlagTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
    ClapTrap clapTrap("Megazord");
    ScavTrap scavTrap("Daimon");
    FragTrap fragTrap("Robocop");
  
    std::cout << "\n";
    std::cout << clapTrap << "\n";
    std::cout << scavTrap << "\n";
    std::cout << fragTrap<< "\n";

    clapTrap.attack(scavTrap.getName());
    scavTrap.takeDamage(clapTrap.getAD());
    clapTrap.beRepaired(50);
    std::cout << "\n";

    scavTrap.attack(clapTrap.getName());
    clapTrap.takeDamage(scavTrap.getAD());
    scavTrap.guardGate();
    scavTrap.beRepaired(50);
    std::cout << "\n";

    fragTrap.attack(scavTrap.getName());
    scavTrap.takeDamage(fragTrap.getAD());
    fragTrap.highFiveGuys();
    fragTrap.beRepaired(40);
    std::cout << "\n";

    std::cout << clapTrap << "\n";
    std::cout << scavTrap << "\n";
    std::cout << fragTrap << "\n";

    return (0);
}
