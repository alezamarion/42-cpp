/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azamario <azamario@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 16:53:32 by azamario          #+#    #+#             */
/*   Updated: 2023/05/07 16:58:56 by azamario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

int main(void)
{
    std::string str = "HI THIS IS BRAIN";
    std::string* stringPTR = &str;
    std::string& stringREF = str;

    std::cout << "\nThe memory address of the string variable:\t " << &str << std::endl;
    std::cout << "The memory address held by stringPTR:\t\t " << stringPTR << std::endl;
    std::cout << "The memory address held by stringREF:\t\t " << &stringREF << std::endl;

    std::cout << "\nThe value of the string variable:\t\t " << str << std::endl;
    std::cout << "The value pointed to by stringPTR:\t\t " << *stringPTR << std::endl;
    std::cout << "The value pointed to by stringREF:\t\t " << stringREF << std::endl;

    std::cout << std::endl;

    return 0;  
}
