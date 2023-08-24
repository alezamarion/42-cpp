/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azamario <azamario@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 22:40:47 by azamario          #+#    #+#             */
/*   Updated: 2023/06/26 12:39:01 by azamario         ###   ########.fr       */
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

		if (num < 0)
			return (false);        
		this->_inputVector.push_back(num);
	}
	return (true);
}

bool PmergeMe::hasDuplicate(void)
{
    _printOrderedVector = this->_inputVector;
    std::sort(_printOrderedVector.begin(), _printOrderedVector.end(), &PmergeMe::compare);
    return (std::unique(_printOrderedVector.begin(), _printOrderedVector.end()) != _printOrderedVector.end());
}

bool PmergeMe::compare(unsigned int a, unsigned int b)
{
	return a < b;
}

void PmergeMe::printUnsorted(void)
{
    int i = 0;
    
    for (std::vector<unsigned int>::const_iterator it = _inputVector.begin(); it != _inputVector.end(); ++it)
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
    
    for (std::vector<unsigned int>::const_iterator it = _printOrderedVector.begin(); it != _printOrderedVector.end(); ++it)
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


/*  Ford–Johnson VECTOR algorithm  */

void PmergeMe::sortVector()
{
	unsigned int straggler = -1;
	std::vector<unsigned int> copy(this->_inputVector);
	std::vector<std::pair<unsigned int, unsigned int> > pairs;

  	std::vector<unsigned int> mainSeq, pendingSeq, jacobSeq, indexSeq;

  	if (copy.size() < 2 or isSorted(copy))
	{
		return;
  	}
  	if (hasStraggler(copy))
	{
    	straggler = copy.back();
    	copy.pop_back();
  	}
 	pairs = createVectorPairs(copy);
	sortPairs(pairs);
  	insertionSortByLargestValue(pairs, pairs.size());
 	mainSeq = createVectorMainSeq(pairs);
	pendingSeq = createVectorPendingSeq(pairs);
	jacobSeq = createJacobsthalSeq(pendingSeq);
  	indexSeq = createIndexSeq(jacobSeq, pendingSeq);
    fillMainSeq(mainSeq, indexSeq, pendingSeq);
  	if (straggler >= 0)
    	insertStraggler(mainSeq, straggler);
	copy.assign(mainSeq.begin(), mainSeq.end());
}

std::vector<std::pair<uint, uint> >
PmergeMe::createVectorPairs(std::vector<uint> &copy)
{
	std::vector<uint>::iterator it, next;
  	std::vector<std::pair<uint, uint> > pairs;

  	it = copy.begin();
  	while (it != copy.end())
	{
    	next = it + 1;
    	pairs.push_back(std::make_pair(*it, *next));
    	it += 2;
  	}
  	return (pairs);
}

std::vector<uint> PmergeMe::createVectorMainSeq(std::vector<std::pair<uint, uint> > &pairs)
{
  std::vector<uint> mainSeq;
  std::vector<std::pair<uint, uint> >::iterator it = pairs.begin();

  for (it = pairs.begin(); it != pairs.end(); it++)
  {
	mainSeq.push_back(it->second);
  }
  return (mainSeq);
}

std::vector<uint> PmergeMe::createVectorPendingSeq(std::vector<std::pair<uint, uint> > &pairs)
{
  std::vector<uint> mainSeq;
  std::vector<std::pair<uint, uint> >::iterator it;

  for (it = pairs.begin(); it != pairs.end(); it++)
  {
    mainSeq.push_back(it->first);
  }
  return (mainSeq);
}

int PmergeMe::jacobsthal(int n)
{
  if (n == 0)
    return (0);
  if (n == 1)
    return (1);
  return (jacobsthal(n - 1) + 2 * jacobsthal(n - 2));
}


/*  Ford–Johnson DEQUE algorithm  */


