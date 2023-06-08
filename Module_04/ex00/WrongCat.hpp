/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azamario <azamario@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 12:53:42 by azamario          #+#    #+#             */
/*   Updated: 2023/06/06 14:43:19 by azamario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"
class WrongCat : public WrongAnimal
{
    public:
        WrongCat();
        WrongCat(WrongCat const &src);
        ~WrongCat();

        WrongCat &operator=(WrongCat const &rhs);

        void makeSound(void) const;

};

#endif
