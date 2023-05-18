/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.tpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azamario <azamario@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 21:22:06 by azamario          #+#    #+#             */
/*   Updated: 2023/05/17 21:28:07 by azamario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_TPP
#define SPAN_TPP

#include "Span.hpp"

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
