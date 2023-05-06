/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azamario <azamario@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 16:03:41 by azamario          #+#    #+#             */
/*   Updated: 2023/05/06 17:15:19 by azamario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HHP
#define PHONEBOOK_HHP

#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>

#include "Contact.hpp"

class PhoneBook
{
    public:
        PhoneBook(void);
        ~PhoneBook(void);

        void addContact(std::string firstName, std::string lastName, std::string nickName,
                        std::string phoneNumber, std::string darkestSecret);
        void printOneContact(Contact contact);
        void formatPrinting(std::string str);
        void printAllContacts(void);
        void searchContact(int index);
        int  getContactCount(void);

    private:
        Contact _contacts[8];
        int _index;
        int _count;
};

#endif
