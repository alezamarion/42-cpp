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


/*  Ford–Johnson algorithm  */

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


// void PmergeMe::sortVector()
// {
// 	std::vector<unsigned int> copy(this->_inputVector);
// 	std::vector<std::pair<unsigned int, unsigned int> > K_pairs;
// 	unsigned int bucket[2];
// 	this->_orderedVector.reserve(this->_inputVector.size() + 2);
// 	while (copy.size() > 1)										
// 	{
// 		bucket[0] = copy.front();
// 		copy.erase(copy.begin());
// 		bucket[1] = copy.front();
// 		copy.erase(copy.begin());
// 		if (bucket[0] < bucket[1])
// 			K_pairs.push_back(std::make_pair(bucket[0],bucket[1]));
// 		else
// 			K_pairs.push_back(std::make_pair(bucket[1],bucket[0]));
// 	}
// 	std::sort(K_pairs.begin(), K_pairs.end(), &PmergeMe::pairCompare);
// 	for (std::vector<std::pair<unsigned int, unsigned int> >::iterator it = K_pairs.begin(); it < K_pairs.end(); it++)
// 	{
// 		this->_orderedVector.push_back((*it).second);
// 	}
// 	for (std::vector<std::pair<unsigned int, unsigned int> >::iterator it = K_pairs.begin(); it < K_pairs.end(); it++)
// 	{
// 		this->binaryVectorInsert((*it).first);
// 	}
// 	if (_inputVector.size() == 1)
// 		this->binaryVectorInsert(_inputVector.front());
// };

void PmergeMe::sortList()
{
	std::deque<unsigned int> copy(this->_inputDeque);
	std::deque<std::pair<unsigned int, unsigned int> > K_pairs;
	unsigned int bucket[2];

	while (copy.size() > 1)
	{
		bucket[0] = copy.front();
		copy.pop_front();
		bucket[1] = copy.front();
		copy.pop_front();
		if (bucket[0] < bucket[1])
			K_pairs.push_back(std::make_pair(bucket[0],bucket[1]));
		else
			K_pairs.push_back(std::make_pair(bucket[1],bucket[0]));
	}
	std::sort(K_pairs.begin(), K_pairs.end(), &PmergeMe::pairCompare);
	for (std::deque<std::pair<unsigned int, unsigned int> >::iterator it = K_pairs.begin(); it < K_pairs.end(); it++)
	{
		this->_orderedList.push_back((*it).second);
	}
	for (std::deque<std::pair<unsigned int, unsigned int> >::iterator it = K_pairs.begin(); it < K_pairs.end(); it++)
	{
		this->binaryListInsert((*it).first);
	}
	if (copy.size() == 1)
		this->binaryListInsert(copy.front());
}
	
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

bool PmergeMe::pairCompare(std::pair<unsigned int, unsigned int> a, std::pair<unsigned int, unsigned int> b)
{
	return (a.second < b.second);
}
