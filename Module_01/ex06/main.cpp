/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azamario <azamario@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 21:49:24 by azamario          #+#    #+#             */
/*   Updated: 2023/05/24 13:05:41 by azamario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int argc, char* argv[])
{
    Harl harl;

    if(argc != 2 )
    {
        std::cerr << "\nWrong amount of parameters! Two needed.\n" << std::endl;
        return (1);
    }
    harl.complain(argv[1]);

    return (0);
}