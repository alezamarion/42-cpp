/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azamario <azamario@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 17:05:00 by azamario          #+#    #+#             */
/*   Updated: 2023/05/16 17:25:18 by azamario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_CPP
#define WHATEVER_CPP

#include <iostream>

template <typename T>
void swap(T &a, T &b)
{
    T temp;
    
    temp = a;
    a = b;
    b = temp;
}

template <typename T>
T min (T a, T b)
{
    return (a < b) ? a : b;
}

template <typename T>
T max (T a, T b)
{
    return (a > b) ? a : b;
}

#endif