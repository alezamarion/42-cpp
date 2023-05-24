/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azamario <azamario@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 21:45:07 by azamario          #+#    #+#             */
/*   Updated: 2023/05/24 13:04:25 by azamario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void Harl::debug(void)
{
    std::cout <<
    "\n[ DEBUG ]"
    "\nI love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger."
    "\nI really do!" << std::endl;
}

void Harl::info(void)
{
    std::cout <<
    "\n[ INFO ]"
    "\nI cannot believe adding extra bacon costs more money. You didn't put"
    " enough bacon in my burger! \nIf you did, I wouldn't be asking for more!" << std::endl;
}

void Harl::warning(void)
{
    std::cout <<
    "\n[ WARNING ]"
    "\nI think I deserve to have some extra bacon for free. \nI've been coming for"
    " years whereas you started working here since last month." << std::endl;
}

void Harl::error(void)
{
	std::cout <<
    "\n[ ERROR ]"
	"\nThis is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::complain(std::string level)
{
    std::string complainLevel[4] = {"debug", "info", "warning", "error"};
    void (Harl::*ptrFunc[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
    size_t opt;

	for(opt = 0; opt < 4; opt++)
    {   
        if(!complainLevel[opt].compare(level))
            break;
    }

    switch (opt)
    {
    case 0:
    { 
        (this->*ptrFunc[0])();
        std::cout << std::endl;
        __attribute__((fallthrough));
    }
    case 1:
    { 
        (this->*ptrFunc[1])();
        std::cout << std::endl;
        __attribute__((fallthrough));
    }
    case 2:
    { 
        (this->*ptrFunc[2])();
        std::cout << std::endl;
        __attribute__((fallthrough));
    }
    case 3:
    { 
        (this->*ptrFunc[3])();
        std::cout << std::endl;
        break;
    }
    default:
        std::cout << "\n[ Probably complaining about insignificant problems ]\n" << std::endl;
        break;
    }
    return;
}
