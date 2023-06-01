/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azamario <azamario@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 16:38:08 by azamario          #+#    #+#             */
/*   Updated: 2023/06/01 20:09:52 by azamario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
    Zombie* zombie_array = new Zombie[N];
    
    for(int i = 0; i < N; i++)
    {
        zombie_array[i].setName(name);
    }
 
    return zombie_array;
}
