/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azamario <azamario@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 20:19:32 by azamario          #+#    #+#             */
/*   Updated: 2023/05/08 20:57:44 by azamario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <string>

class ClapTrap
{
    public:
        ClapTrap(void);
        explicit ClapTrap(std::string const name);
        ClapTrap(ClapTrap const &src);
        ~ClapTrap(void);

        ClapTrap &operator=(ClapTrap const &rhs);
        
        std::string getName(void) const;
        unsigned int getHP(void) const;
        unsigned int getEP(void) const;
        unsigned int getAD(void) const;

        void setName(std::string const &name);
        void setHP(unsigned int hitPoints);
        void setEP(unsigned int energyPoints);
        void setAD(unsigned int attackDamage);

        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);

    private:
        std::string const _name;
        unsigned int _hitPoint;
        unsigned int _energyPoint;
        unsigned int _attackDamage;            
};

std::ostream &operator<<(std::ostream &out, ClapTrap const &in);

#endif