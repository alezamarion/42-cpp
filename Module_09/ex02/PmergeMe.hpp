/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azamario <azamario@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 22:34:20 by azamario          #+#    #+#             */
/*   Updated: 2023/06/21 16:59:26 by azamario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <deque>
#include <list>
#include <algorithm>

/*	The template class PmergeMe provides generic functionality for handling containers of various types T. 
    It includes operations such as sorting, merging, checking for duplicates, and printing container elements. */
template <typename T>
class PmergeMe
{
    public:
        PmergeMe(void);
        PmergeMe(const PmergeMe<T> &src);
        ~PmergeMe(void);

        PmergeMe &operator=(const PmergeMe<T> &rhs);

        bool hasDuplicate(T &container);
        void mergeSort(T &container);
        void mergeSort(T &container, typename T::iterator begin, typename T::iterator end);
        void mergeMe(typename T::iterator begin, typename T::iterator middle, typename T::iterator end);
        void printMe(T &container);
};

#endif

/*	The reason for having two versions of mergeSort is to provide flexibility and convenience to the user. 
	Sometimes, the user may want to sort the entire container, while in other cases, they may only need to sort a specific range of elements within 
		the container. 
	By providing both versions, the PmergeMe class caters to both scenarios without the need for the user to manually extract a sub-range of elements 
		before sorting.
	Having the flexibility to sort specific ranges can be useful when dealing with large containers or when sorting different parts of the container 
		separately based on specific requirements.
	Overall, the two versions of mergeSort allow for more flexibility in sorting containers, providing options to sort either the entire container or a 
		specific range based on the user's needs. */
