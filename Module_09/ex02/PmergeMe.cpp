/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azamario <azamario@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 22:40:47 by azamario          #+#    #+#             */
/*   Updated: 2023/06/24 22:49:46 by azamario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(void)
{
    return;
}

PmergeMe::PmergeMe(const PmergeMe &src)
{
    *this = src;
}

PmergeMe::~PmergeMe(void)
{
    return;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &rhs)
{
    if (this != &rhs)
        *this = rhs;
    return (*this);
}

bool PmergeMe::loadList(int argc, char** argv)
{
	for (int i = 1; i < argc; ++i)
	{
		int num = std::atoi(argv[i]);

		if (num <= 0)
			return (false);        
		this->_inputDeque.push_back(num);
	}
	return (true);
}

bool PmergeMe::hasDuplicate(void)
{
    _orderedDeque = this->_inputDeque;
    std::sort(_orderedDeque.begin(), _orderedDeque.end(), &PmergeMe::compare);
    return (std::unique(_orderedDeque.begin(), _orderedDeque.end()) != _orderedDeque.end());
}

bool PmergeMe::compare(unsigned int a, unsigned int b)
{
	return a < b;
}

void PmergeMe::printUnsorted(void)
{
    int i = 0;
    
    for (std::deque<unsigned int>::const_iterator it = _inputDeque.begin(); it != _inputDeque.end(); ++it)
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

void PmergeMe::printSorted(void)
{
    int i = 0;
    
    for (std::deque<unsigned int>::const_iterator it = _orderedDeque.begin(); it != _orderedDeque.end(); ++it)
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

size_t PmergeMe::containerSize(void)
{
	return this->_inputDeque.size();
}

/*  Ford–Johnson algorithm  */

/* Steps:
	1 - Determine if the array is even or odd numbered in length. If odd, remove the last number, designate it as a 
	‘straggler’ and insert it later into the sorted array.
	2 - Arbitrarily divide the sequence to sort into pairs of two values.
	3 - Sort the pairs, so the order is always [less, greater].
	4 - Sort the sequence recursively by the value of it’s largest pair.
	5 - Create a new sequence ‘S’, by pulling out the [highest] value of each pair and inserting it into ‘S’.
	6 - The remaining values form a temporary ‘pend’ array.
	7 - Loop through the elements in ‘pend’, and using the use binary search to insert each ‘pend’ element into ‘S’.
	8 - If a ‘straggler’ was found, do a leftover loop and insertion to complete the list.

	The main differences between the two implementations lie in the choice of data structures used to store 
	the sorted elements.
*/

//vector implementation
void PmergeMe::sortVector()
{
	std::deque<unsigned int> copy(this->_inputDeque);
	std::deque<std::pair<unsigned int, unsigned int> > K_pairs;
	unsigned int bucket[2];
	this->_orderedVector.reserve(this->_inputDeque.size() + 2);
	while (copy.size() > 1)	//1										
	{
		//create pairs (already inner-ordered), if odd, there will be a leftover value
		bucket[0] = copy.front(); //2
		copy.pop_front();
		bucket[1] = copy.front();
		copy.pop_front();
		if (bucket[0] < bucket[1]) //3
			K_pairs.push_back(std::make_pair(bucket[0],bucket[1]));
		else
			K_pairs.push_back(std::make_pair(bucket[1],bucket[0]));
	}
	std::sort(K_pairs.begin(), K_pairs.end(), &PmergeMe::pairCompare); //4
	for (std::deque<std::pair<unsigned int, unsigned int> >::iterator it = K_pairs.begin(); it < K_pairs.end(); it++) //5
	{
		this->_orderedVector.push_back((*it).second);
	}
	for (std::deque<std::pair<unsigned int, unsigned int> >::iterator it = K_pairs.begin(); it < K_pairs.end(); it++) //6
	{
		this->binaryVectorInsert((*it).first);
	}
	if (copy.size() == 1) //7-8
		this->binaryVectorInsert(copy.front());
};

//list implementation
void PmergeMe::sortList()
{
	std::deque<unsigned int> copy(this->_inputDeque);
	std::deque<std::pair<unsigned int, unsigned int> > K_pairs;
	unsigned int bucket[2];

	while (copy.size() > 1) //1
	{
		//create pairs (already inner-ordered), if odd, there will be a leftover value
		bucket[0] = copy.front(); //3
		copy.pop_front();
		bucket[1] = copy.front();
		copy.pop_front();
		if (bucket[0] < bucket[1])
			K_pairs.push_back(std::make_pair(bucket[0],bucket[1]));
		else
			K_pairs.push_back(std::make_pair(bucket[1],bucket[0]));
	}
	std::sort(K_pairs.begin(), K_pairs.end(), &PmergeMe::pairCompare); //4
	for (std::deque<std::pair<unsigned int, unsigned int> >::iterator it = K_pairs.begin(); it < K_pairs.end(); it++) //5
	{
		this->_orderedList.push_back((*it).second);
	}
	for (std::deque<std::pair<unsigned int, unsigned int> >::iterator it = K_pairs.begin(); it < K_pairs.end(); it++) //6
	{
		this->binaryListInsert((*it).first);
	}
	if (copy.size() == 1) //7-8
		this->binaryListInsert(copy.front());
}

/*	- The function uses the std::lower_bound() algorithm to find the position in the sorted list where the value 
	should be inserted. lower_bound() returns an iterator pointing to the first element that is not less than 
	the value.
	- The iterator it obtained from lower_bound() points to the position in the list where the value should 
	be inserted.
	- The insert() function takes the iterator it and the value as arguments, and it adjusts the list's internal 
	structure to insert the value at the correct position. */
	
void PmergeMe::binaryVectorInsert(unsigned int value)
{
	std::vector<unsigned int>::iterator it = std::lower_bound(this->_orderedVector.begin(), this->_orderedVector.end(), value);
	this->_orderedVector.insert(it, value);
}

void PmergeMe::binaryListInsert(unsigned int value)
{
	std::list<unsigned int>::iterator it = std::lower_bound(this->_orderedList.begin(), this->_orderedList.end(), value);
	this->_orderedList.insert(it, value);
}

/*	The purpose of the Pair_compare function is to define the sorting order for pairs of unsigned integers based on 
	their second elements. By returning true when a.second is less than b.second, the function establishes an ordering
	that sorts pairs in ascending order based on their second element. */
bool PmergeMe::pairCompare(std::pair<unsigned int, unsigned int> a, std::pair<unsigned int, unsigned int> b)
{
	return (a.second < b.second);
}
