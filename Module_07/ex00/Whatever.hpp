/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azamario <azamario@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 17:05:00 by azamario          #+#    #+#             */
/*   Updated: 2023/06/15 22:00:12 by azamario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_CPP
#define WHATEVER_CPP

#include <iostream>


/*
    Typename indica que T é um tipo de parâmetro
    This template function swap allows you to swap the values of two variables of any type by using pass-by-reference 
    and a temporary variable. The benefit of using a template function is that it can be used with different types of 
    variables without the need for separate implementations for each type.
*/
template <typename T> 
void swap(T &a, T &b)
{
    T temp;
    
    temp = a;
    a = b;
    b = temp;
}

/*
    The & symbol indicates that the parameters are passed by reference, and const ensures that the values of a and b 
    cannot be modified within the function. The return type is a constant reference to T.
    This template function min allows you to find the minimum value between two variables of any type by comparing their 
    values using the less-than operator. The function returns a constant reference to the minimum value, ensuring that the
    original values of a and b remain unaltered. 
*/

template <typename T>
const T& min(const T &a, const T &b)
{
    return (a < b) ? a : b;
}

template <typename T>
const T& max(const T &a, const T &b)
{
    return (a > b) ? a : b;
}

#endif