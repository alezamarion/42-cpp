/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azamario <azamario@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 23:57:42 by azamario          #+#    #+#             */
/*   Updated: 2023/05/13 00:11:45 by azamario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <cstdlib>
#include <sstream>
#include <string>
#include <iostream>

class ScalarConverter
{
    public:
        ScalarConverter(void);
        explicit ScalarConverter(const std::string& inputRaw);
        ScalarConverter(ScalarConverter& src);
        ~ScalarConverter(void);

        ScalarConverter& operator=(const ScalarConverter& rhs);

        operator char();
        operator int();
        operator float();
        operator double();
        
        std::string getInput(void) const;
        double getRaw(void) const;

        std::string castingChar();
        std::string castingInt();
        std::string castingFloat();
        std::string castingDouble();     

    private:
        const std::string _input;
        double _raw;
};

#endif
