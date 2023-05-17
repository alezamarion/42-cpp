/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azamario <azamario@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 20:55:06 by azamario          #+#    #+#             */
/*   Updated: 2023/05/17 10:12:54 by azamario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <cstddef>
#include <stdexcept>

template <typename T>
class Array
{
    public:
        Array<T>(void) : _size(0), _ptr(NULL)
        {
            return;
        }

        explicit Array<T>(unsigned int n) : _size(n), ptr(NULL)
        {
            if (this->_size)
            {
                this->_ptr = new T(this->_size);
            }
        }

        
        
    private:
        site_t _size;
        T* _ptr;
    
};



#endif
