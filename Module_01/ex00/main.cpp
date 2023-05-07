/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azamario <azamario@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 16:10:38 by azamario          #+#    #+#             */
/*   Updated: 2023/05/07 16:23:08 by azamario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
    Zombie z1("ale");
    z1.announce();
    
    Zombie *ptr_z2 = newZombie("\nAllocated zombie");
    ptr_z2->announce();
    delete ptr_z2;

    randomChump("\nStack zombie");

    return (0);
}