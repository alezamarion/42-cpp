/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azamario <azamario@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 16:50:34 by azamario          #+#    #+#             */
/*   Updated: 2023/06/18 19:35:45 by azamario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_TPP
#define MUTANTSTACK_TPP

#include "MutantStack.hpp"

/*	The provided copy constructor initializes the base class (std::stack) using the default constructor and then 
	copies the contents of the source MutantStack object into the newly created object using the assignment operator.
	
	Template Declaration: template <typename T>
	This line declares a template for a class or function with a template parameter T, which represents the type of 
	elements stored in the MutantStack.

	Constructor Definition: MutantStack<T>::MutantStack(const MutantStack<T>& src) : std::stack<T>()
	This line defines the copy constructor for the MutantStack class, taking a constant reference to another MutantStack 
	object src as its parameter.

	The : std::stack<T>() part of the code is an initialization list that invokes the base class (std::stack) default 
	constructor. It ensures that the base class part of the MutantStack object is properly initialized.

	Copy Assignment: *this = src;
	This line performs the actual copying of the elements from the source MutantStack src to the newly created 
	MutantStack object. The *this pointer refers to the current object (the one being constructed), and the assignment
	operator (operator=) is used to copy the contents of src into *this.
	By using the assignment operator (operator=), the copy constructor delegates the task of copying the elements to 
	the assignment operator implementation. This allows code reuse and ensures consistent behavior between copy 
	construction and copy assignment.
*/

template <typename T>
MutantStack<T>::MutantStack(const MutantStack<T>& src) : std::stack<T>()
{
    *this = src;
};

/*	The assignment operator copies the contents of the source MutantStack object (rhs) into the current object (*this).
	It ensures that the base class part of the MutantStack object is properly assigned by invoking the base class's 
	assignment operator. Finally, it returns a reference to the current object to support chaining of assignment 
	operations.

	Template Declaration: template <typename T>
	This line declares a template for a class or function with a template parameter T, which represents the type of 
	elements stored in the MutantStack.

	Operator Overloading: MutantStack<T>& MutantStack<T>::operator=(const MutantStack<T>& rhs)
	This line defines the assignment operator for the MutantStack class, taking a constant reference to another 
	MutantStack object rhs as its parameter. The return type MutantStack<T>& indicates that the operator returns a 
	reference to the MutantStack object itself, allowing chaining of assignment operations.

	Base Class Assignment: std::stack<T>::operator=(rhs)
	This line invokes the assignment operator of the base class (std::stack) to copy the elements from the source 
	MutantStack rhs into the current object (*this). By using the scope resolution operator (::), it explicitly 
	specifies that the base class's assignment operator should be used.

	Return Reference: return (*this);
	This line returns a reference to the current MutantStack object after the assignment operation.
	By returning (*this), it allows chaining of assignment operations like stack1 = stack2 = stack3, where the 
	assignment is applied from right to left.
*/

template <typename T>
MutantStack<T>& MutantStack<T>::operator=(const MutantStack<T>& rhs)
{
    std::stack<T>::operator=(rhs);
    return (*this);
};     

#endif
