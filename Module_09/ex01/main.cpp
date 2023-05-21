/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azamario <azamario@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 20:28:19 by azamario          #+#    #+#             */
/*   Updated: 2023/05/20 22:17:03 by azamario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        std::cerr << "Usage: ./RPN <RPN expression>" << std::endl;
        return (1);
    }

    ReversePolishNotation calculator;

    std::string expression = argv[1];

    try
	{
        double result = calculator.evaluate(expression);
        std::cout << "\nResult: " << result << std::endl << std::endl;
    }
    catch (std::exception &excep)
    {
        std::cerr << excep.what() << std::endl;
    }
    return (0);
}
