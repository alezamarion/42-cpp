/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azamario <azamario@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 12:29:15 by azamario          #+#    #+#             */
/*   Updated: 2023/06/09 17:34:55 by azamario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
    public:
        Cat(void);
        Cat(Cat const &src);
        virtual ~Cat(void);

        Cat &operator=(Cat const &rhs);
    
        Brain const *getBrain(void) const;
        virtual void makeSound(void) const;

    private:
        Brain* _brain;
};

#endif
