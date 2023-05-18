/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azamario <azamario@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 14:57:34 by azamario          #+#    #+#             */
/*   Updated: 2023/05/18 15:32:29 by azamario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

const char* Span::NotEnoughCapacity::what(void) const throw()
{
    return ("Not enough capacity");
}

const char* Span::InsufficientElements::what(void) const throw()
{
    return ("Insufficient elements");
}

Span::Span(void) : _vector(std::vector<int>()), _maximum(0)
{
    return;
}

Span::Span(size_t maximum) : _vector(std::vector<int>()), _maximum(maximum)
{
    return;
}

Span::Span(const Span& src): _vector(std::vector<int>()), _maximum(src.getMaximum())
{
    *this = src;
}

Span::~Span(void)
{
    return;
}

Span& Span::operator=(const Span& rhs)
{
    if(this != &rhs)
    {
        this->_vector = std::vector<int>(rhs.getContainer());
        this->_maximum = rhs.getMaximum();
    }
    return (*this);
}

const std::vector<int>& Span::getContainer(void) const
{
    return (this->_vector);
}

size_t Span::getMaximum(void) const
{
    return (this->_maximum);
}

size_t Span::getSize(void) const
{
    return (this->_vector.size());
}

int Span::getValueAt(size_t pos)
{
    return (this->_vector.at(pos));
}

void Span::addNumber(int n)
{
    if (this->_vector.size() == this->_maximum)
        throw NotEnoughCapacity();
    else
        this->_vector.push_back(n);
}

size_t Span::shortestSpan(void)
{
    std::vector<int>copyVect(this->_vector);
    std::vector<int>::iterator it;
    int diff;
    
    if (this->_vector.size() < 2)
    {
        throw InsufficientElements();
        diff = 0;
    }
    else
        diff = INT_MAX;
    
    std::sort(copyVect.begin(), copyVect.end());
    for (it = this->_vector.begin() + 1; it != this->_vector.end(); it++)
    {
        if (std::abs(*it - *(it -1)) < diff)
            diff = abs(*it - *(it -1));
    }
    return (diff);
}

size_t Span::longestSpan(void)
{
    if (this->_vector.size() < 2)
        throw InsufficientElements();
    std::vector<int>::iterator it1 = std::min_element(this->_vector.begin(), this->_vector.end());
    std::vector<int>::iterator it2 = std::max_element(this->_vector.begin(), this->_vector.end());

    return (*it2 - *it1);
}
