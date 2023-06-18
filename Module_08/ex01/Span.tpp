/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.tpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azamario <azamario@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 21:22:06 by azamario          #+#    #+#             */
/*   Updated: 2023/06/18 19:33:26 by azamario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_TPP
#define SPAN_TPP

#include "Span.hpp"

/*	This code adds a range of elements specified by the iterators itBegin and itEnd to the vector _vector. 
	It checks if there is enough capacity to accommodate the elements and throws an exception if there is 
	insufficient capacity. If the capacity is sufficient, it iterates through the range and adds each element 
	to the vector.
*/
template <typename T>
void Span::addRange(T itBegin, T itEnd)
{
    size_t maxCapacity = this->_maximum - this->_vector.size();
    if(std::distance(itBegin, itEnd) > static_cast<int>(maxCapacity))
    {
        throw NotEnoughCapacity();
    }
    while(itBegin != itEnd)
    {
        this->_vector.push_back(*itBegin);
        itBegin++;
    }       
}

#endif
