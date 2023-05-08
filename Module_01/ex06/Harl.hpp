/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azamario <azamario@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 21:44:37 by azamario          #+#    #+#             */
/*   Updated: 2023/05/07 21:44:43 by azamario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
#define HARL_HPP

#include <string>
#include <iostream>

class Harl
{
    public:
        Harl() {}
        ~Harl() {}
        void complain(std::string level);

    private:
        void debug(void);
        void info(void);
        void warning(void);
        void error(void);
};

#endif