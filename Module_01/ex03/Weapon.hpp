/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azamario <azamario@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 17:07:27 by azamario          #+#    #+#             */
/*   Updated: 2023/05/07 17:14:41 by azamario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>
#include <iostream>

class Weapon
{
    public:
        explicit Weapon(std::string type);
        ~Weapon() {}
        const std::string &getType(void) const;
        void setType(std::string type);
        
    private:
        std::string _type;     
};

#endif