/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azamario <azamario@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 15:33:21 by azamario          #+#    #+#             */
/*   Updated: 2023/05/18 15:58:24 by azamario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <list>
#include <vector>

#include "Span.hpp"

int main()
{
    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;
    
    return 0;
}


/*
int main()
{
    Span sp1 = Span(10000);
    Span sp2 = Span(25000);
    Span sp3 = Span(1);
    Span sp4 = Span(5);

    std::list<int> vect(10000, 0);
    sp1.addRange(vect.begin(), vect.end());

    std::cout << "[ Vector 1: 10K Size ]\n";
    std::cout << "Result: " << sp1.getSize() << "\n\n";

    std::cout << "[ Vector 1: not space ]\n";
    try
    {
        sp1.addRange(vect.begin(), vect.end());
    } 
    catch (const std::exception& e)
    {
        std::cerr << e.what() << "\n\n";
    }

    for (int i = 0; i < 25000; i++)
    {
        sp2.addNumber(i);
    }

    std::cout << "[ Vector 2: 25K Size ]\n";
    std::cout << "Result: " << sp2.getSize() << "\n\n";

    sp3.addNumber(1);
    std::cout << "[ Vector 3: not space ]\n";
    try
    {
        sp3.addNumber(99);
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << "\n\n";
    }

    std::cout << "[ Vector 3: Shortest Span ]\n";
    try
    {
        sp3.shortestSpan();
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << "\n\n";
    }

    std::cout << "[ Vector 3: Longest Span ]\n";
    try
    {
        sp3.longestSpan();
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << "\n\n";
    }

    sp4.addNumber(6);
    sp4.addNumber(3);
    sp4.addNumber(17);
    sp4.addNumber(9);
    sp4.addNumber(11);

    std::cout << "[ Vector 4: Size ]\n";
    std::cout << "Result: " << sp4.getSize() << "\n\n";

    std::cout << "[ Vector 4: Shortest Span ]\n";
    std::cout << "Result: " << sp4.shortestSpan() << "\n\n";

    std::cout << "[ Vector 4: Longest Span ]\n";
    std::cout << "Result: " << sp4.longestSpan() << "\n";

    return 0;
}

*/
/*
int main()
{

	std::cout << std::endl;

	unsigned int N = 10;

	{
		Span sp = Span(N);
		std::vector<int> vec;

		int j = 1;

		std::cout << std::endl << "Numbers: ";

		for (unsigned int i = 0; i < N; i++)
		{
			std::cout << j;

      		if (i < N - 1)
				std::cout << ", ";
        
			sp.addNumber(j);
			vec.push_back(j);
			
      		j *= 2;
		}

		std::cout << std::endl << std::endl;

		std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest  Span: " << sp.longestSpan() << std::endl;
	}

	std::cout << std::endl;

	{
		Span sp = Span(N);
		std::vector<int> vec;

		int j = 1;

		std::cout << std::endl << "Numbers: ";

		for (unsigned int i = 0; i < N; i++)
		{
			std::cout << j;

			if (i < N - 1)
				std::cout << ", ";
        
			sp.addNumber(j);
			vec.push_back(j);
			
      		j *= 3;
		}

		std::cout << std::endl << std::endl;

		std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest  Span: " << sp.longestSpan() << std::endl;
	}

	std::cout << std::endl;

	{
		Span sp = Span(N);
		std::vector<int> vec;

		int j = 1024;

		std::cout << std::endl << "Numbers: ";

		for (unsigned int i = 0; i < N; i++)
		{
			std::cout << j;

			if (i < N - 1)
				std::cout << ", ";
        
			sp.addNumber(j);
			vec.push_back(j);
			
      		j /= -2;
		}

		std::cout << std::endl << std::endl;

		std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest  Span: " << sp.longestSpan() << std::endl;
	}

	std::cout << std::endl << std::endl;

	{
		Span sp = Span(10);

		try
		{
			std::cout << "Try shortestSpan in Span(0): ";
			std::cout << sp.shortestSpan() << std::endl;
		}
		catch(std::exception &excep)
		{
			std::cout << excep.what() << std::endl;
		}

		try
		{
			std::cout << "Try longestSpan  in Span(0): ";
			std::cout << sp.longestSpan() << std::endl;
		}
		catch(std::exception &excep)
		{
			std::cout << excep.what() << std::endl;
		}

		std::cout << std::endl;

		sp.addNumber(1);

		try
		{
			std::cout << "Try shortestSpan in Span(1): ";
			std::cout << sp.shortestSpan() << std::endl;
		}
		catch(std::exception &excep)
		{
			std::cout << excep.what() << std::endl;
		}

		try
		{
			std::cout << "Try longestSpan  in Span(1): ";
			std::cout << sp.longestSpan() << std::endl;
		}
		catch(std::exception &excep)
		{
			std::cout << excep.what() << std::endl;
		}

		std::cout << std::endl;

		try
		{
			std::cout << "Try addNumber  in full Span: ";

			for (unsigned int i = 0; i < 12; i++)
				sp.addNumber(i);

			std::cout << "Success" << std::endl;
		}
		catch(std::exception &excep)
		{
			std::cout << excep.what() << std::endl;
		}
	}

	{
		Span sp = Span(1000);

		for (unsigned int i = 0; i < 1000; i++)
		{
			srand(clock());
			sp.addNumber(rand());
		}

		std::cout << std::endl << std::endl;

		std::cout << "Test with random Span(10.000)" << std::endl << std::endl;

		std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest  Span: " << sp.longestSpan() << std::endl;
	}

	{
		Span sp = Span(10000);

		for (unsigned int i = 0; i < 10000; i++)
		{
			srand(clock());
			sp.addNumber(rand());
		}

		std::cout << std::endl << std::endl;

		std::cout << "Test with random Span(100.000)" << std::endl << std::endl;

		std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest  Span: " << sp.longestSpan() << std::endl;
	}

	{
		Span sp = Span(100000);

		for (unsigned int i = 0; i < 10000; i++)
		{
			srand(clock());
			sp.addNumber(rand());
		}

		std::cout << std::endl << std::endl;

		std::cout << "Test with random Span(1.000.000)" << std::endl << std::endl;
    
		std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest  Span: " << sp.longestSpan() << std::endl;
	}

	std::cout << std::endl;

	return (0);

}
*/