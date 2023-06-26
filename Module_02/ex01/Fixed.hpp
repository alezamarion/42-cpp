/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azamario <azamario@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 11:03:37 by azamario          #+#    #+#             */
/*   Updated: 2023/06/26 12:22:28 by azamario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
    public:
        Fixed(void);
        Fixed(Fixed const &src);
        explicit Fixed(int const n);
        explicit Fixed(float const f);
        ~Fixed(void);

        Fixed &operator=(Fixed const &src);

        int getRawBits(void) const;
        void setRawBits(int const raw);
        float toFloat(void) const;
        int toInt(void) const;

    private:
        int _rawBits;
        static int const _fractionalBits;
};

std::ostream &operator<<(std::ostream &output_stream, Fixed const &fixed_number);

#endif