/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azamario <azamario@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 16:03:52 by azamario          #+#    #+#             */
/*   Updated: 2023/05/06 17:52:48 by azamario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <string>


bool fieldValidation(std::string input, std::string fieldName);

bool phoneValidation(std::string input, std::string fieldName);

void addContact(PhoneBook &objPhoneBook);

void searchContact(PhoneBook objPhoneBook);


int main(void)
{
    PhoneBook objPhoneBook;
    std::string option;

    while (1)
    {
        std::cout << "Choose one option: " << std::endl;
        std::cout << "Option: ADD | SEARCH | EXIT" << std::endl;
        std::cin >> option;

        if (option == "ADD")
            addContact(objPhoneBook);
        else if (option == "SEARCH")
            searchContact(objPhoneBook);
        else if (option == "EXIT")
            break;
        else
            std::cout << "Invalid option" << std::endl;
    }
    return (0);
}