/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azamario <azamario@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 16:28:31 by azamario          #+#    #+#             */
/*   Updated: 2023/06/01 20:09:33 by azamario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie
{
    public:
        Zombie(void);
        ~Zombie(void);
        void announce(void);
        void setName(std::string name);

    private:
        std::string _name;
};

Zombie* zombieHorde(int N, std::string name);

#endif
