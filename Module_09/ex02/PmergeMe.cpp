/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azamario <azamario@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 22:40:47 by azamario          #+#    #+#             */
/*   Updated: 2023/06/21 16:59:46 by azamario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

template <typename T>
PmergeMe<T>::PmergeMe(void)
{
    return;
}

template <typename T>
PmergeMe<T>::PmergeMe(const PmergeMe &src)
{
    *this = src;
}

template <typename T>
PmergeMe<T>::~PmergeMe(void)
{
    return;
}

template <typename T>
PmergeMe<T> &PmergeMe<T>::operator=(const PmergeMe<T> &rhs)
{
    if (this != &rhs)
        *this = rhs;
    return (*this);
}

/*	This function creates a sorted copy of the input container, sorts it using the mergeSort algorithm, and then checks for duplicates using the 
	std::unique algorithm. By comparing the iterators before and after the std::unique operation, the function determines whether the original 
	container contains any duplicate elements and returns a bool value accordingly. */

template <typename T>
bool PmergeMe<T>::hasDuplicate(T &container)
{
    T sortedContainer = container;
    mergeSort(sortedContainer);
    
	/* The function compares the iterator returned by std::unique with the end iterator of the sortedContainer. 
	   If they are equal, it means that there were no duplicates in the original container, and the function returns false. 
	   Otherwise, it means that there were duplicates, and the function returns true. */
	return (std::unique(sortedContainer.begin(), sortedContainer.end()) != sortedContainer.end());
}

/* This implementation of mergeSort provides a convenient way to sort the entire container by utilizing the overloaded mergeSort function 
	that works on specific ranges within the container. 
   This call to mergeSort effectively initiates the merge sort algorithm on the entire range of elements in the container.
   By calling the overloaded mergeSort function with the container, its begin iterator, and its end iterator, the mergeSort function sorts the elements
	in the container using the merge sort algorithm. */
template <typename T>
void PmergeMe<T>::mergeSort(T &container)
{
    mergeSort(container, container.begin(), container.end());
}

/* This code is an implementation of the merge sort algorithm for a generic container T. It recursively divides the container into smaller 
   subcontainers until the base case is reached (when begin == end or there is only one element between begin and end), 
   and then merges the sorted subcontainers back together. */
template <typename T>
void PmergeMe<T>::mergeSort(T &container, typename T::iterator begin, typename T::iterator end)
{
	//base case, range contains 0 or 1 element
    if (begin == end || ++begin == end)
        return;
	//iterator is adjusted by decrementing it, so it points to the actual first element of the range.
    --begin;
	/*  The middle point of the range is determined by calculating the distance between begin and end and dividing it by 2. 
	    The std::advance function is used to move the middle iterator to the correct position in the container. */
    typename T::iterator middle = begin;
    std::advance(middle, std::distance(begin, end) / 2);

	/* Recursively calls mergeSort on the left half of the range (begin to middle) and the right half of the range (middle to end), effectively 
	   dividing the problem into smaller subproblems. */
    mergeSort(container, begin, middle);
    mergeSort(container, middle, end);
    
	/* Finally, the mergeMe function is called to merge the sorted halves together. This is where the actual merging of elements happens */
	mergeMe(begin, middle, end);
}

/* This function is responsible for merging two sorted halves of a container back into a single sorted container. The mergeMe function takes three 
   parameters: begin, middle, and end. These iterators define the range of elements to be merged. The begin iterator points to the beginning 
   of the range, middle points to the middle element, and end points to one past the last element.*/
template <typename T>
void PmergeMe<T>::mergeMe(typename T::iterator begin, typename T::iterator middle, typename T::iterator end)
{
	/* The function creates two temporary containers, left and right, and copies the elements from the left and right halves of the range into 
	   these containers. */
    T left(begin, middle);
    T right(middle, end);
    
	/* Iterators leftIt, rightIt, and mergeIt are initialized. leftIt and rightIt iterate over the left and right containers, respectively, 
	   while mergeIt iterates over the original container to merge the sorted elements. */
    typename T::iterator leftIt = left.begin();
    typename T::iterator rightIt = right.begin();
    typename T::iterator mergeIt = begin;

	/* The function enters a loop that compares the elements pointed to by leftIt and rightIt. If the element in the left container is less than 
	   or equal to the element in the right container, it is copied to the merged container using *mergeIt = *leftIt, and leftIt is incremented. 
	   Otherwise, the element from the right container is copied, and rightIt is incremented. In either case, mergeIt is also incremented. */
    while (leftIt != left.end() && rightIt != right.end())
    {
        if (*leftIt <= *rightIt)
        {
            *mergeIt = *leftIt;
            ++leftIt;
        }
        else
        {
            *mergeIt = *rightIt;
            ++rightIt;
        }
        ++mergeIt;
    }
	/* After the loop, there may be remaining elements in either the left or right containers. The remaining elements in the left container 
	   are copied to the merged container using another loop, and then the remaining elements in the right container are copied similarly. 
	   The result is that the merged container, starting from begin, contains all the elements from the original range (begin to end) in sorted order.*/
    while (leftIt != left.end())
    {
        *mergeIt = *leftIt;
        ++leftIt;
        ++mergeIt;
    }
    while (rightIt != right.end())
    {
        *mergeIt = *rightIt;
        ++rightIt;
        ++mergeIt;
    }
}

template <typename T>
void PmergeMe<T>::printMe(T &container)
{
    int i = 0;
    
    for (typename T::const_iterator it = container.begin(); it != container.end(); ++it)
    {
        std::cout << *it << " ";
        i++;
        if (i >= 15)
        {
            std::cout << "[...]";
            break;
        }
    }
    std::cout << std::endl;
}

/*  The explicit template instantiations are included in the same source file or compilation unit as the member function definitions 
    to ensure that the necessary code is generated for the specific types used in the instantiations.*/
template class PmergeMe < std::deque<int> >;
template class PmergeMe < std::list<int> >;
