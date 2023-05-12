/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azamario <azamario@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 12:50:16 by azamario          #+#    #+#             */
/*   Updated: 2023/05/12 12:52:54 by azamario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>
#include <string>
class WrongAnimal
{
    public:
        WrongAnimal(void);
        explicit WrongAnimal(std::string const type);
        WrongAnimal(WrongAnimal const &src);
        virtual ~WrongAnimal(void);

        WrongAnimal &operator=(WrongAnimal const &rhs);

        std::string const getType(void) const;
        void setType(std::string const type);
        void makeSound(void) const;

    protected:
    std::string _type;
};

std::ostream &operator<<(std::ostream &out, WrongAnimal const &in);

#endif
