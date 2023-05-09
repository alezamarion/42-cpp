/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azamario <azamario@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 21:25:25 by azamario          #+#    #+#             */
/*   Updated: 2023/05/09 13:51:01 by azamario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
    public:
        ScavTrap(void);
        explicit ScavTrap(std::string const name);
        ScavTrap(ScavTrap const &src);
        ~ScavTrap(void);
        
        ScavTrap &operator=(ScavTrap const &rhs);

        void attack(const std::string &target);
        void guardGate(void) const;      
};

#endif