/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azamario <azamario@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 16:03:52 by azamario          #+#    #+#             */
/*   Updated: 2023/05/06 23:28:29 by azamario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <string>


bool fieldValidation(std::string input, std::string fieldName)
{
    for(std::string::iterator i = input.begin(); i != input.end(); ++i)
    {
        if (!std::isalnum(*i))
        {
            std::cout << fieldName << " - Character not allowed: " << *i <<std::endl;
            return (false);
        }
    }
    return (true);    
}

bool phoneValidation(std::string input, std::string fieldName)
{
    for(std::string::iterator i = input.begin(); i != input.end(); ++i)
    {
        if (!std::isdigit(*i))
        {
            std::cout << fieldName << " - Character not allowed: " << *i <<std::endl;
            return (false);
        }
    }
    return (true);
}

void addContact(PhoneBook &objPhoneBook)
{
    std::string firstName;
    std::string lastName;
    std::string nickName;
    std::string phoneNumber;
    std::string darkestSecret;

    std::cin.ignore();
    std::cout << "Input First Name: " << std::endl;
    std::getline(std::cin, firstName);
    if(!fieldValidation(firstName, "First Name"))
        return;
    std::cout << "Input Last Name: " << std::endl;
    std::getline(std::cin, lastName);
    if(!fieldValidation(lastName, "Last Name"))
        return;
    std::cout << "Input Nick Name" << std::endl;
    std::getline(std::cin, nickName);
    if(!fieldValidation(nickName, "Nick Name"))
        return;
    std::cout << "Input Phone Number" << std::endl;
    std::getline(std::cin, phoneNumber);
    if(!phoneValidation(phoneNumber, "Phone Number"))
        return;
    std::cout << "Input Darkest Secret" << std::endl;
    std::getline(std::cin, darkestSecret);
    if(!fieldValidation(darkestSecret, "Darkest Secret"))
        return;
    objPhoneBook.addContact(firstName, lastName, nickName, phoneNumber, darkestSecret);
    std::cout << std::endl << "Contact " << firstName << " added to your phonebook" << std::endl;   
}

void searchContact(PhoneBook objPhoneBook)
{
    std::string option;
    std::stringstream ss;
    int index;

    if(objPhoneBook.getContactCount() == 0)
    {
        std::cout << "Phonebook is empty." << std::endl;
        return;
    }
    objPhoneBook.printAllContacts();
    std::cout << "Choose a contact by index: " << std::endl;
    std::cin >> option;
    ss << option;
    ss >> index;
    objPhoneBook.searchContact(index - 1);
}

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
