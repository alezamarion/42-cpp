/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azamario <azamario@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 17:30:34 by azamario          #+#    #+#             */
/*   Updated: 2023/05/07 17:35:39 by azamario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"

class HumanB
{
    public:
        explicit HumanB(std::string name);
        ~HumanB() {}
        void attack(void) const;
        void setWeapon(Weapon &weapon);

    private:
        std::string _name;
        Weapon *_weapon; //no HumanA é uma referência
};

#endif
