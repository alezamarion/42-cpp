/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azamario <azamario@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 20:05:53 by azamario          #+#    #+#             */
/*   Updated: 2023/06/21 16:58:36 by azamario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

ReversePolishNotation::ReversePolishNotation(void)
{
    return;
}

ReversePolishNotation::ReversePolishNotation(const ReversePolishNotation &src)
{
    *this = src;
}

ReversePolishNotation::~ReversePolishNotation(void)
{
    return;
}

ReversePolishNotation &ReversePolishNotation::operator=(const ReversePolishNotation &rhs)
{
    if (this != &rhs)
        *this = rhs;
    return (*this);
}

/*	This function evaluates an arithmetic expression in Reverse Polish Notation (RPN) by using a stack to store operands and performing 
	the corresponding arithmetic operations based on the encountered operators. It throws errors for cases such as insufficient operands or 
	invalid characters.
*/

double ReversePolishNotation::evaluate(std::string expression)
{
    std::stack<double>operandStack;
    std::string token(expression);

    int i = -1;

	//The loop iterates over each character in the token string
    while (token[++i])
    {	
		//If first char is space, move to second
        if (token[i] == ' ')
            continue;

		/* If the current character is a digit, the function assumes it is an operand and pushes its numerical value (converted from character to double) 
		   onto the operandStack using the expression operandStack.push(token[i] - '0'). The subtraction of '0' converts the character representation of 
		   a digit to its corresponding numerical value. */
        else if (isdigit(token[i]))
            operandStack.push(token[i] - '0');

		/* If the current character is an operator ('+', '-', '*', or '/'), the function checks if there are at least two operands on the operandStack. 
		   If not, it throws a std::runtime_error with a message indicating that there are not enough operands to perform the operation. */
        else if (token[i] == '+' || token[i] == '-' || token[i] == '*' || token[i] == '/')
        {
            if (operandStack.size() < 2)
                throw std::runtime_error("\nError: not enough operands\n");

			/* If there are at least two operands on the stack, the function proceeds to perform the operation based on the current operator. 
			   It pops the top two operands from the operandStack and assigns them to rhs (right-hand side) and lhs (left-hand side) respectively. 
			   It then performs the appropriate arithmetic operation based on the operator and pushes the result back onto the operandStack. */
            double rhs = operandStack.top();
            operandStack.pop();
            double lhs = operandStack.top();
            operandStack.pop();
            if (token[i] == '+')
                operandStack.push(lhs + rhs);
            else if (token[i] == '-')
                operandStack.push(lhs - rhs);
            else if (token[i] == '*')
                operandStack.push(lhs * rhs);
            else if (token[i] == '/')
                operandStack.push(lhs / rhs);            
        }
		//If the current character is neither a space, digit, nor operator, the function throws a std::runtime_error
        else
            throw std::runtime_error("\nError: invalid character\n");        
    }
	/* After evaluating all characters in the token string, the function returns the top element from the operandStack, which represents 
	   the final result of the RPN expression. */
    return (operandStack.top());  
}

const char* ReversePolishNotation::Error::what() const throw()
{
    return ("Error");
}
