/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azamario <azamario@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 22:34:20 by azamario          #+#    #+#             */
/*   Updated: 2023/06/24 22:40:48 by azamario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <stdexcept>
#include <algorithm>
#include <deque>
#include <vector>
#include <list>

class PmergeMe
{
    public:
        PmergeMe(void);
        PmergeMe(const PmergeMe &src);
        ~PmergeMe(void);

        PmergeMe &operator=(const PmergeMe &rhs);

		// load and validate list
		bool loadList(int argc, char **argv);
        bool hasDuplicate(void);
		static bool compare(unsigned int a, unsigned int b);

		// get and show data before using algorithm with Vector and List
        void printUnsorted(void);
        void printSorted(void);
		size_t containerSize(void);

		// Ford–Johnson algorithm implementation
		void sortList(void);
		void binaryListInsert(unsigned int value);
		void sortVector(void);
		void binaryVectorInsert(unsigned int value);
		static bool Pair_compare(std::pair<unsigned int, unsigned int> a, std::pair<unsigned int, unsigned int> b);

	private:
		std::deque<unsigned int> _inputDeque;
		std::deque<unsigned int> _orderedDeque;
		std::list<unsigned int> _orderedList;
		std::vector<unsigned int> _orderedVector;
};

#endif
