/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azamario <azamario@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 12:04:05 by azamario          #+#    #+#             */
/*   Updated: 2023/05/12 12:08:03 by azamario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>

class Animal
{
    public:
        Animal(void);
        explicit Animal(std::string const type);
        Animal(Animal const &src);
        virtual ~Animal(void);
        
        Animal &operator=(Animal const &rhs);
        
        std::string const getType(void) const;
        void setType(std::string const type);
        virtual void makeSound(void) const;
        
    protected:
        std::string _type;
};

std::ostream &operator <<(std::ostream &out, Animal const &in);

#endif