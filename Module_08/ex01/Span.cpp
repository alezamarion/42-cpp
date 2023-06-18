/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azamario <azamario@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 14:57:34 by azamario          #+#    #+#             */
/*   Updated: 2023/06/18 19:32:43 by azamario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(void)
{
    return;
}

Span::Span(unsigned int maximum) : _maximum(maximum)
{
    return;
}

Span::Span(const Span& src): _maximum(src.getMaximum())
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

/*	This function creates a copy of the original vector, sorts it, and then iterates through the sorted vector 
	to find the smallest difference between adjacent elements. It handles the case of insufficient elements and 
	returns the shortest span.
*/

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
	/*	If the vector has at least two elements, the function assigns diff the maximum possible integer value INT_MAX,
		indicating that any calculated difference will be smaller than this initial value.
	*/
    else
        diff = INT_MAX;
    
	//sorts the copyVect vector in ascending order
    std::sort(copyVect.begin(), copyVect.end());
    for (it = this->_vector.begin() + 1; it != this->_vector.end(); it++)
    {
		/*	calculates the absolute difference between the current element *it and the previous element *(it - 1)
			using std::abs(*it - *(it -1)). If this calculated difference is smaller than the current diff, 
			it updates diff with the new, smaller value.
		*/
        if (std::abs(*it - *(it -1)) < diff)
            diff = abs(*it - *(it -1));
    }
    return (diff);
}

/*	This code first checks if the vector has enough elements, and if so, it finds the iterators (position) 
	for the minimum and maximum elements using std::min_element() and std::max_element(). 
	Finally, it returns the difference between the maximum and minimum values, representing the longest span 
	(maximum difference) between elements in the vector.
*/
size_t Span::longestSpan(void)
{
    if (this->_vector.size() < 2)
        throw InsufficientElements();
    std::vector<int>::iterator it1 = std::min_element(this->_vector.begin(), this->_vector.end());
    std::vector<int>::iterator it2 = std::max_element(this->_vector.begin(), this->_vector.end());

    return (*it2 - *it1);
}

void Span::printVector() const
{
	std::vector<int>::const_iterator it;
	std::cout << "[ ";
    for (it = _vector.begin(); it != _vector.end(); ++it)
	{
        std::cout << *it << " ";
    }
	std::cout << "]\n\n";
};

const char* Span::NotEnoughCapacity::what(void) const throw()
{
    return ("Not enough capacity");
}

const char* Span::InsufficientElements::what(void) const throw()
{
    return ("Insufficient elements");
}
