/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azamario <azamario@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 20:55:06 by azamario          #+#    #+#             */
/*   Updated: 2023/06/15 22:23:20 by azamario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <cstddef>
#include <stdexcept>

/*
    The Array class template provides a flexible and dynamic array implementation that can be used with any type T. 
    It includes constructors, a destructor, assignment operator, subscript operator, and a member function to retrieve 
    the size of the array.
*/


//This line declares a class template with a template parameter T, which represents the type of elements in the array. 
//The typename keyword indicates that T is a type parameter.

template <typename T>
class Array
{
    public:
        //default constructor
        Array<T>(void) : _size(0), _ptr(NULL)
        {
            return;
        }
        //parametric constructor, inicializa n e aloca memória para ponteiro se n > 0
        explicit Array<T>(unsigned int n) : _size(n), _ptr(NULL)
        {
            if (this->_size)
            {
                this->_ptr = new T[this->_size];
            }
        }
        //copy constructor, faz deep copy de src para _ptr
        Array<T>(const Array<T>& src) : _size(src.size()), _ptr(NULL)
        {
            if(this->_size)
                this->_ptr = new T[this->_size];
            *this = src;
        }
        //destructor: dá free na memória e reseta ponteiro para NULL e size para 0
        ~Array<T>(void)
        {
            if(this->_size)
                delete[] this->_ptr;
            this->_ptr = NULL;
            this->_size = 0;
        }
        //assignment operator:
        // - dá free na memória alocada para _ptr e faz deep copy de rhs para a nova alocação de ponteiro
        // - retorna uma referência para a array
        Array<T>& operator=(const Array<T>& rhs)
        {
            if(this->_size)
                delete[] this->_ptr;
            this->_size = rhs.size();
            if(this->_size)
                this->_ptr = new T[this->_size];
            for(size_t i = 0; i < this->size(); i++)
                this->_ptr[i] = rhs[i]; 
            return (*this);
        }
        /*  This is the subscript operator declaration for non-const objects. It allows accessing and modifying elements 
            in the array at the specified index i. It performs bounds checking and throws an std::out_of_range exception 
            if the index is out of range.
        */
        T& operator[](size_t i)
        {
            if(i < 0 || i >= this->_size)
                throw std::out_of_range("The index is out of range\n");
            return (this->_ptr[i]);
        }
        /*  This is the subscript operator declaration for const objects. It allows accessing elements in the array at the 
            specified index i but does not allow modification. It also performs bounds checking and throws an 
            std::out_of_range exception if the index is out of range.
        */
        const T& operator[](size_t i) const
        {
            if(i < 0 || i >= this->_size)
                throw std::out_of_range("The index is out of range\n");
            return (this->_ptr[i]);
       }
       //retorna o tamanho da array
       size_t size(void) const
       {
            return (this->_size);
       }
              
    private:
        size_t _size;
        T* _ptr;        //pointer to dynamically allocated memory that holds the elements of the array.
};

/*  This function enables you to use the insertion operator (<<) to output the contents of an Array object to the 
    standard output stream. It iterates over the elements of the Array, printing them one by one with spaces separating 
    them and a newline character at the end.
*/
template <typename T>
std::ostream& operator<<(std::ostream& out, const Array<T>& in)
{
    for(size_t i = 0; i < in.size(); i++)
    {
        std::cout << in[i];
        if(i + 1 < in.size()) //checks if the current element is not the last element in the Array. 
            std::cout << " "; //If it is not, it outputs a space character after the element to separate them.
    }
    std::cout << "\n";
    return(out);
}

#endif
