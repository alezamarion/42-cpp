/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azamario <azamario@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 11:03:37 by azamario          #+#    #+#             */
/*   Updated: 2023/06/04 12:42:48 by azamario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

/**
 * @brief 
 * setRawBits(int const raw) define os bits brutos armazenados na classe para um valor inteiro fornecido.
   toFloat() retorna o valor do número de ponto fixo como um número de ponto flutuante.
   toInt() retorna o valor do número de ponto fixo como um inteiro.
 
 * _rawBits: um inteiro que armazena o valor do número de ponto fixo em um formato de ponto fixo com
    a quantidade fixa de bits fracionais.
   _fractionalBits: um inteiro constante e estático que representa a quantidade fixa de bits fracionais. 
   
 * sobrecarga do operador de fluxo de saída (<<) definida fora da classe Fixed que permite que um objeto 
    Fixed seja impresso na tela usando o operador <<.
**/

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