/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azamario <azamario@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 14:28:34 by azamario          #+#    #+#             */
/*   Updated: 2023/05/12 14:28:36 by azamario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

class Dog : public AAnimal
{
    public:
        Dog(void);
        Dog(Dog const &src);
        virtual ~Dog();

        Dog &operator=(Dog const &rhs);

        Brain const *getBrain(void) const;
        void makeSound(void) const;
    
    private:
        Brain* _brain;

};

#endif
