/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azamario <azamario@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 12:39:49 by azamario          #+#    #+#             */
/*   Updated: 2023/05/12 12:40:02 by azamario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal
{
    public:
    Dog(void);
    Dog(Dog const &src);
    virtual ~Dog();

    Dog &operator=(Dog const &rhs);

    void makeSound(void) const;

};

#endif