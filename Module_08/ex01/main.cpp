/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azamario <azamario@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 15:33:21 by azamario          #+#    #+#             */
/*   Updated: 2023/06/18 19:32:00 by azamario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main()
{
	{
		std::cout << "\n[ TEST 0: PDF TEST ]\n\n";
	
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}


	{
		std::cout << "\n[ TEST 1: VECTOR SIZE 0 ]\n";

		Span sp0(0);
		std::cout << "\n-> Exception: Not Space <-\n";
		try
		{
			sp0.addNumber(9);
		}
		catch (const std::exception& e)
		{
			std::cerr << e.what() << "\n\n";
		}
		std::cout << "-> Exception: Shortest Span <-\n";
		try
		{
			sp0.shortestSpan();
		}
		catch (const std::exception& e)
		{
			std::cerr << e.what() << "\n\n";
		}
		std::cout << "-> Exception: Longest Span <-\n";
		try
		{
			sp0.longestSpan();
		}
		catch (const std::exception& e)
		{
			std::cerr << e.what() << "\n\n";
		}
	}


	{
		std::cout << "\n[ TEST 2: VECTOR SIZE 1 ]\n";

		Span sp1(1);
		sp1.addNumber(1);
		std::cout << "\n-> Exception: Not Space <-\n";
		try
		{
			sp1.addNumber(9);
		}
		catch (const std::exception& e)
		{
			std::cerr << e.what() << "\n\n";
		}
		std::cout << "-> Exception: Shortest Span <-\n";
		try
		{
			sp1.shortestSpan();
		}
		catch (const std::exception& e)
		{
			std::cerr << e.what() << "\n\n";
		}
		std::cout << "-> Exception: Longest Span <-\n";
		try
		{
			sp1.longestSpan();
		}
		catch (const std::exception& e)
		{
			std::cerr << e.what() << "\n\n";
		}
	}


	{
		std::cout << "\n[ TEST 3: VECTOR SIZE 10 ]\n";

		Span sp2(10);
		int j = 1;
		for (int i = 0; i < 10; i++)
		{
			sp2.addNumber(j);
			j *= 5;
		}
		std::cout << "\nVector: "; sp2.printVector();
		std::cout << "-> Shortest Span <-\n";
		std::cout << "Result: " << sp2.shortestSpan() << "\n\n";

		std::cout << "-> Longest Span <-\n";
		std::cout << "Result: " << sp2.longestSpan() << "\n\n";
	}


	{
		std::cout << "\n[ TEST 4: VECTOR SIZE 10K ]\n";

		Span sp3(10000);

		std::vector<int> vector(10000);
		int j = 1;
		for (int i = 0; i < 10000; ++i)
		{
			vector[i] = j;
			j += 2;
		}
		sp3.addRange(vector.begin(), vector.end());

		std::cout << "-> Vector Size: <-\n";
		std::cout << "Result: " << sp3.getSize() << "\n\n";

		std::cout << "-> Exception: not space <-\n";
		try
		{
			sp3.addNumber(10);
		}
		catch (const std::exception& e)
		{
			std::cerr << e.what() << "\n\n";
		}

		std::cout << "-> Shortest Span <-\n";
		std::cout << "Result: " << sp3.shortestSpan() << "\n\n";

		std::cout << "-> Longest Span <-\n";
		std::cout << "Result: " << sp3.longestSpan();
		int firstElement = vector.front();
		int lastElement = vector.back();
		std::cout << " | first element is: "<< firstElement << " | last element is " << lastElement << "\n\n";
	}


	{
		std::cout << "\n[ TEST 5: VECTOR SIZE 1M ]\n";
		
		Span sp4(1000000);

		std::vector<int> vector(1000000);
		int j = 5;
		for (int i = 0; i < 1000000; ++i)
		{
			vector[i] = j;
			j += 5;
		}
		sp4.addRange(vector.begin(), vector.end());

		std::cout << "-> Vector Size: <-\n";
		std::cout << "Result: " << sp4.getSize() << "\n\n";

		std::cout << "-> Exception: not space <-\n";
		try
		{
			sp4.addNumber(10);
		}
		catch (const std::exception& e)
		{
			std::cerr << e.what() << "\n\n";
		}

		std::cout << "-> Shortest Span <-\n";
		std::cout << "Result: " << sp4.shortestSpan() << "\n\n";

		std::cout << "-> Longest Span <-\n";
		std::cout << "Result: " << sp4.longestSpan();
		int firstElement = vector.front();
		int lastElement = vector.back();
		std::cout << " | first element is: "<< firstElement << " | last element is " << lastElement << "\n\n";
	}

    return 0;
}
