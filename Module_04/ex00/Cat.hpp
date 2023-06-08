/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azamario <azamario@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 12:29:15 by azamario          #+#    #+#             */
/*   Updated: 2023/06/06 14:40:58 by azamario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal
{
    public:
    Cat(void);
    Cat(Cat const &src);
    ~Cat(void); //não precisa ser colocado como virtual, já é automaticamente

    Cat &operator=(Cat const &rhs);

    virtual void makeSound(void) const; //boa prática colocar como virtual para dar visibilidade
};

#endif
