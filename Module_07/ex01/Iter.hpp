/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azamario <azamario@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 18:08:54 by azamario          #+#    #+#             */
/*   Updated: 2023/05/16 20:29:22 by azamario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T>
void iter(T* address, size_t lenght, void (*f)(const T&))
{
    for(size_t i = 0; i < lenght; i++)
        f(address[i]);
}

template <typename T>
void printArray(const T& n)
{
    std::cout << n << " ";
}

#endif
