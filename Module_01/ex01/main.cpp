/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azamario <azamario@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 16:41:32 by azamario          #+#    #+#             */
/*   Updated: 2023/05/07 16:44:46 by azamario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
    Zombie* zumbilandia;

    zumbilandia = zombieHorde(10, "ale");

    for(int i = 0; i < 10; i++)
    {
        zumbilandia[i].announce();
    }
    delete[] zumbilandia;

    return (0);
}
