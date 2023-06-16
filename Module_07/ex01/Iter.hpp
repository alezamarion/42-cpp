/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azamario <azamario@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 18:08:54 by azamario          #+#    #+#             */
/*   Updated: 2023/06/15 22:03:46 by azamario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

/*
    This template function iter allows you to iterate over an array of any type and apply a given function to each element.
    The function pointer f provides flexibility to pass any function that matches the required signature:
    (void (*)(const T&)). This function can be useful when you want to perform some operation on each element of an array 
    without having to write a separate loop each time.
*/

template <typename T>
void iter(T* array, size_t lenght, void (*f)(const T&))
{
    for(size_t i = 0; i < lenght; i++)
        f(array[i]);
}

/*
    The printArray function is designed to be used with different types of variables. 
    It relies on the fact that the << operator is overloaded for the appropriate types to enable printing to the standard 
    output stream. 
*/

template <typename T>
void printArray(const T& n)
{
    std::cout << n << " ";
}

#endif
