/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azamario <azamario@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 21:08:08 by azamario          #+#    #+#             */
/*   Updated: 2023/05/18 14:54:07 by azamario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <algorithm>
#include <climits>
#include <exception>
#include <vector>


class Span
{
    public:
        class NotEnoughCapacity : public std::exception
        {
            public:
                const char* what(void) const throw();          
        };
        
        class InsufficientElements : public std::exception
        {
            public:
                const char* what(void) const throw();                     
        };

        Span(void);
        explicit Span(size_t maximum);
        Span(const Span& src);
        ~Span(void);

        Span& operator=(const Span& rhs);

        const std::vector<int>& getContainer(void) const;
        size_t getMaximum(void) const;
        size_t getSize(void) const;
        int getValueAt(size_t pos);

        void addNumber(int n);

        template <typename T>
        void addRange(T itBegin, T itEnd);

        size_t shortestSpan(void);
        size_t longestSpan(void);
        
    private:
        std::vector<int> _vector;
        size_t _maximum;
};

#include "Span.tpp"

#endif
