/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azamario <azamario@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 21:23:37 by azamario          #+#    #+#             */
/*   Updated: 2023/06/02 22:36:48 by azamario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl(void)
{
	return;
}

Harl::~Harl(void)
{
	return;
}

void Harl::debug(void)
{
    std::cout <<
    "\nI love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger."
    " I really do!\n" << std::endl;
}

void Harl::info(void)
{
    std::cout <<
    "\nI cannot believe adding extra bacon costs more money. You didn't put"
    " enough bacon in my burger! If you did, I wouldn't be asking for more!\n" << std::endl;
}

void Harl::warning(void)
{
    std::cout <<
    "\nI think I deserve to have some extra bacon for free. I've been coming for"
    " years whereas you started working here since last month.\n" << std::endl;
}

void Harl::error(void)
{
	std::cout <<
	"\nThis is unacceptable! I want to speak to the manager now.\n" << std::endl;
}


/* The complain function allows you to complain at different levels by specifying the complaint level as a string.
It uses an array of strings and an array of function pointers to member functions to map the complaint level to the 
appropriate action. When a complaint level matches the input level, the associated member function is called through 
the function pointer, allowing specific actions to be taken based on the complaint level. */
void Harl::complain(std::string level)
{
    std::string complainLevel[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    
    /* an array of function pointers to member functions of the Harl class. Each function pointer corresponds to a 
    complaint level and points to a member function of Harl that handles that particular level of complaint. */
    void (Harl::*ptrFunc[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
    
    for(int i = 0; i < 4; i++)
    {
        /* compare() returns 0 if strings are equal, '!' allows entry into the block of 'if' */
        if(!complainLevel[i].compare(level))
        {
            /* invokes the corresponding member function of the Harl class through the 'this' pointer. 
            In other words, it calls the member function associated with the matching complaint level.*/
            (this->*ptrFunc[i])();
            return;
        }
    }
    std::cout <<
	"\nNo complains, I'm happy! :D\n" << std::endl;
    return;
}
