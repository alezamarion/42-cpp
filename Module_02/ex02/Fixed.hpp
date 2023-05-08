/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azamario <azamario@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 11:15:17 by azamario          #+#    #+#             */
/*   Updated: 2023/05/08 11:18:08 by azamario         ###   ########.fr       */
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

        bool operator>(Fixed const &src) const;
        bool operator<(Fixed const &src) const;
        bool operator>=(Fixed const &src) const;
        bool operator<=(Fixed const &src) const;
        bool operator==(Fixed const &src) const;
        bool operator!=(Fixed const &src) const;

        Fixed operator+(Fixed const &src);
        Fixed operator-(Fixed const &src);
        Fixed operator*(Fixed const &src);
        Fixed operator/(Fixed const &src);

        Fixed &operator++(void);
        Fixed operator++(int);
        Fixed &operator--(void);
        Fixed operator--(int);

        static Fixed &min(Fixed &lhs, Fixed &rhs);
        static Fixed const &min(Fixed const &lhs, Fixed const &rhs);
        static Fixed &max(Fixed &lhs, Fixed &rhs);
        static Fixed const &max(Fixed const &lhs, Fixed const &rhs);

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
