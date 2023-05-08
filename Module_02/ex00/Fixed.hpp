/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azamario <azamario@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 10:37:02 by azamario          #+#    #+#             */
/*   Updated: 2023/05/08 11:47:22 by azamario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
    public:
        Fixed(void);
        Fixed(Fixed const &src);
        ~Fixed(void);
        
        Fixed &operator=(Fixed const &src);
        
        int getRawBits(void) const;
        void setRawBits(int const raw);
        
    private:
        int _rawBits;
        static int const _fractionalBits;
};

#endif