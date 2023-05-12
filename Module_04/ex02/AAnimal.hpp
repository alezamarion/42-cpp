/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azamario <azamario@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 14:26:00 by azamario          #+#    #+#             */
/*   Updated: 2023/05/12 14:26:37 by azamario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
#define AANIMAL_HPP

#include <iostream>
#include <string>

class AAnimal{
    public:
        AAnimal(void);
        explicit AAnimal(std::string const type);
	    AAnimal(AAnimal const &src);
        virtual ~AAnimal(void);

        AAnimal &operator=(AAnimal const &rhs);
    
	    std::string const getType(void) const;
	    void setType(std::string const type);
	    virtual void makeSound(void) const = 0;

    protected:
        std::string _type;
};

std::ostream &operator <<(std::ostream &out, AAnimal const &in);

#endif