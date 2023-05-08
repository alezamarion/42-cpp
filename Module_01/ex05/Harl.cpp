/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azamario <azamario@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 21:23:37 by azamario          #+#    #+#             */
/*   Updated: 2023/05/07 21:38:38 by azamario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void Harl::debug(void)
{
    std::cout <<
    "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger."
    " I really do!" << std::endl;
}

void Harl::info(void)
{
    std::cout <<
    "I cannot believe adding extra bacon costs more money. You didn't put"
    " enough bacon in my burger! If you did, I wouldn't be asking for more!" << std::endl;
}

void Harl::warning(void)
{
    std::cout <<
    "I think I deserve to have some extra bacon for free. I've been coming for"
    " years whereas you started working here since last month." << std::endl;
}

void Harl::error(void)
{
	std::cout <<
	"This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::complain(std::string level)
{
    std::string complainLevel[4] = {"debug", "info", "warning", "error"};
    void (Harl::*ptrFunc[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
    
    for(int i = 0; i < 4; i++)
    {
        if(!complainLevel[i].compare(level))
        {
            (this->*ptrFunc[i])();
            return;
        }
    }
    return;
}
