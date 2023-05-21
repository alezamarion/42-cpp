/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azamario <azamario@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 20:01:15 by azamario          #+#    #+#             */
/*   Updated: 2023/05/20 22:19:25 by azamario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <sstream>
#include <cstdlib>
#include <cctype>
#include <stack>

class ReversePolishNotation
{
    public:
        ReversePolishNotation(void);
        ReversePolishNotation(const ReversePolishNotation &src);
        ~ReversePolishNotation(void);
    
        ReversePolishNotation &operator=(const ReversePolishNotation &rhs);
    
        double evaluate(std::string expression);
    
        class Error : public std::exception
        {
            public:
                virtual const char* what() const throw();
        }; 
};

#endif