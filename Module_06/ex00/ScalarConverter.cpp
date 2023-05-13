/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azamario <azamario@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 00:04:12 by azamario          #+#    #+#             */
/*   Updated: 2023/05/13 00:26:42 by azamario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(void) : _input(""), _raw(0)
{
    std::cout << "Default constructor called\n";
    return;
}

ScalarConverter::ScalarConverter(const std::string& inputRaw) : _input(inputRaw), _raw(0)
{
    std::cout << "Parametric constructor called\n";
    if (inputRaw.length() == 1 && std::isalpha(*inputRaw.begin()))
        this->_raw = static_cast<double>(*inputRaw.begin());
    else
        this->_raw = std::strtod(inputRaw.c_str(), NULL);
}

ScalarConverter::ScalarConverter(ScalarConverter& src)
{
    std::cout << "Copy constructor called\n";
    *this = src;
}

ScalarConverter::~ScalarConverter(void)
{
    std::cout << "Destructor called\n";
    return;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& rhs)
{
    std::cout << "Assignment operator called\n";
    const_cast<std::string&>(this->_input) = rhs.getInput();
    const_cast<double&>(this->_raw) = rhs.getRaw();
    return (*this);
}

ScalarConverter::operator char()
{
    std::cout << "operator char Called\n";
    return(static_cast<char>(this->_raw));   
}

ScalarConverter::operator int()
{
    std::cout << "operator char Called\n";
    return(static_cast<int>(this->_raw));
}

ScalarConverter::operator float()
{
    std::cout << "operator char Called\n";
    return(static_cast<float>(this->_raw));
}

ScalarConverter::operator double()
{
    std::cout << "operator char Called\n";
    return(static_cast<double>(this->_raw)); 
}

std::string ScalarConverter::getInput(void) const
{
    std::cout << "getInput called\n";
    return (this->_input);
}

double ScalarConverter::getRaw(void) const
{
    std::cout << "getRaw called\n";
    return (this->_raw);   
}

std::string ScalarConverter::castingChar()
{
    std::stringstream ss;
    std::cout << "********castingChar*******\n";
    char c = static_cast<char>(ScalarConverter(this->_input));

    if(this->_input.compare("0") && c == 0)
        return("char: impossible");
    else if (!std::isprint(c))
        return ("char: Non displayable");
    else
    {
        ss << "'" << c << "'";
        return ("char: " + ss.str());
    }
}

std::string ScalarConverter::castingInt()
{
    std::cout << "********castingInt*******\n";
    std::stringstream ss;
    int n = static_cast<int>(ScalarConverter(this->_input));

    if ((this->_input.compare("0") && n == 0) || ((this->_input.compare("-2147483648")
    && n == -2147483648)))
        return("int: impossible");
    else
    {
        ss << n;
        return("int: "+ ss.str());
    }    
}

std::string ScalarConverter::castingFloat()
{
    std::cout << "********castingFloat*******\n";
    std::stringstream ss;
    float f = static_cast<float>(ScalarConverter(this->_input));
    int n = static_cast<int>(ScalarConverter(this->_input));

    if(this->_input.compare("0") && f == 0)
        return ("float : impossible");
    else
    {
        ss << f;
        if (static_cast<float>(n) == f)
            ss << ".0f";
        else
            ss << "f";
    }
    return ("float : "+ ss.str());    
}

std::string ScalarConverter::castingDouble()
{
    std::cout << "********castingDouble*******\n";
    std::stringstream ss;
    double d = static_cast<double>(ScalarConverter(this->_input));

    if (this->_input.compare("0") && d == 0)
        return("double: impossible");
    else
    {
        ss << d;
        if (static_cast <int>(d) == d)
            ss << ".0";
        return ("double: "+ ss.str());
    }  
}    
