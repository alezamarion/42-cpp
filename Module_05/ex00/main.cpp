/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azamario <azamario@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 11:02:37 by azamario          #+#    #+#             */
/*   Updated: 2023/06/12 21:05:17 by azamario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void) 
{
	Bureaucrat* bureaucrat;

	std::cout << "\nTESTE 1" << std::endl;
	try
	{
		bureaucrat = new Bureaucrat("Marcos", 0);
	  	std::cout << *bureaucrat;
	  	delete bureaucrat;
  	}
  	catch (std::exception& e) 
  	{
        std::cout << "**catch Marcos**\n";
    	std::cerr << e.what() << "\n";
  	}

	std::cout << "\nTESTE 2" << std::endl;
	try
	{
		bureaucrat = new Bureaucrat("Joao", 1);
	  	std::cout << *bureaucrat;
	  	delete bureaucrat;
  	}
  	catch (std::exception& e) 
  	{
        std::cout << "**catch Joao**\n";
    	std::cerr << e.what() << "\n";
  	}

	std::cout << "\nTESTE 3" << std::endl;
	try
	{
		bureaucrat = new Bureaucrat("Jorge", 1);
	  	bureaucrat->decrementGrade();
		std::cout << *bureaucrat;
	  	delete bureaucrat;
  	}
  	catch (std::exception& e) 
  	{
        std::cout << "**catch Jorge**\n";
    	std::cerr << e.what() << "\n";
  	}

	std::cout << "\nTESTE 4" << std::endl;
	try
	{
		bureaucrat = new Bureaucrat("Roberto", 1);
	  	bureaucrat->incrementGrade();
		std::cout << *bureaucrat;
	  	delete bureaucrat;
  	}
  	catch (std::exception& e) 
  	{
        std::cout << "**catch Roberto**\n";
    	std::cerr << e.what() << "\n";
		delete bureaucrat;
  	}

	std::cout << "\nTESTE 5" << std::endl;
	try
	{
		bureaucrat = new Bureaucrat("Jose", -1);
		std::cout << *bureaucrat;
	  	delete bureaucrat;
  	}
  	catch (std::exception& e) 
  	{
        std::cout << "**catch Jose**\n";
    	std::cerr << e.what() << "\n";
  	}

	std::cout << "\nTESTE 6" << std::endl;
	try
	{
		bureaucrat = new Bureaucrat("Rosana", 150);
	  	bureaucrat->incrementGrade();
		std::cout << *bureaucrat;
	  	delete bureaucrat;
  	}
  	catch (std::exception& e) 
  	{
        std::cout << "**catch Rosana**\n";
    	std::cerr << e.what() << "\n";
  	}

	std::cout << "\nTESTE 7" << std::endl;
	try
	{
		bureaucrat = new Bureaucrat("Roberta", 150);
	  	bureaucrat->decrementGrade();
		std::cout << *bureaucrat;
	  	delete bureaucrat;
  	}
  	catch (std::exception& e) 
  	{
        std::cout << "**catch Roberta**\n";
    	std::cerr << e.what() << "\n";
		delete bureaucrat;
  	}

	std::cout << "\nTESTE 8" << std::endl;
	try
	{
		bureaucrat = new Bureaucrat("Rosa", 151);
		std::cout << *bureaucrat;
	  	delete bureaucrat;
  	}
  	catch (std::exception& e) 
  	{
        std::cout << "**catch Rosa**\n";
    	std::cerr << e.what() << "\n";
  	}
	  
	return (0);
}
