/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azamario <azamario@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 20:45:44 by azamario          #+#    #+#             */
/*   Updated: 2023/05/08 20:47:23 by azamario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{
    ClapTrap temp1;
    ClapTrap temp2("Daimon");
    ClapTrap clap1("Megazord"), clap2(temp2);

    std::cout << "\n";

    clap1.setAD(1);
    clap2.setAD(1);

    clap1.attack(clap2.getName());
    clap2.takeDamage(clap1.getAD());
    clap2.beRepaired(1);
    std::cout << "\n";

    clap2.attack(clap1.getName());
    clap1.takeDamage(clap2.getAD());
    clap2.beRepaired(1);
    std::cout << "\n";

    clap1.setAD(10);
    clap2.setAD(10);

    clap1.attack(clap2.getName());
    clap2.takeDamage(clap1.getAD());
    clap2.beRepaired(1);
    std::cout << "\n";

    for (int i = 0; i < 8; i++)
    {
        clap1.beRepaired(1);
    }

    std::cout << "\n";

    clap1.attack(clap2.getName());
    clap2.takeDamage(clap1.getAD());
    clap2.attack(clap1.getName());

    std::cout << "\n";

    clap1.beRepaired(10);
    clap2.beRepaired(10);

    std::cout << "\n";

    std::cout << clap1 << "\n";
    std::cout << clap2 << "\n";

    return (0);
}