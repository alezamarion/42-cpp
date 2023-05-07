/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azamario <azamario@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 16:38:08 by azamario          #+#    #+#             */
/*   Updated: 2023/05/07 16:45:55 by azamario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int n, std::string _name)
{
    Zombie* zombie_array = new Zombie[n];
    
    for(int i = 0; i < n; i++)
    {
        zombie_array[i].setName(_name);
    }
 
    return zombie_array;
}
