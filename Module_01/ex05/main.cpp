/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azamario <azamario@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 21:30:33 by azamario          #+#    #+#             */
/*   Updated: 2023/05/07 21:40:43 by azamario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int argc, char* argv[])
{
    Harl harl;
    
    if(argc != 2)
    {
        std::cerr << "Wrong amount of parameters! Two needed." << std::endl;
        return (1);
    }
    harl.complain(argv[1]);

    return (0);
}