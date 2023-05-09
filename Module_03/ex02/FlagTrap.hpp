/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FlagTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azamario <azamario@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 13:51:45 by azamario          #+#    #+#             */
/*   Updated: 2023/05/09 13:52:11 by azamario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap: public ClapTrap
{
    public:
        FragTrap(void);
        explicit FragTrap(std::string const name);
        FragTrap(FragTrap const &src);
        ~FragTrap(void);

        FragTrap &operator=(FragTrap const &rhs);

        void highFiveGuys(void);
};
#endif
