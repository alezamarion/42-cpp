/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azamario <azamario@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 11:20:02 by azamario          #+#    #+#             */
/*   Updated: 2023/06/12 21:13:49 by azamario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main(void)
{
	Bureaucrat* b;
  	AForm* f;

  	std::cout << "\n** TEST 1 **\n";
  	try
	{
		b = new Bureaucrat("João", 1);
    	f = new ShrubberyCreationForm("John");
    	b->signForm(*f);
    	std::cout << *f;
    	b->executeForm(*f);
    	delete b;
    	delete f;
  	}
	catch (std::exception& e)
	{
    	std::cerr << e.what() << "\n";
  	}

  	std::cout << "\n** TEST 2 **\n";
  	try
	{
    	b = new Bureaucrat("Maria", 1);
    	f = new RobotomyRequestForm("Mary");
    	b->signForm(*f);
    	std::cout << *f;
    	b->executeForm(*f);
    	delete b;
    	delete f;
  	}
	catch (std::exception& e)
	{
    	std::cerr << e.what() << "\n";
  	}

  	std::cout << "\n** TEST 3 **\n";
  	try
	{
    	b = new Bureaucrat("Carolina", 1);
    	f = new PresidentialPardonForm("Caroline");
    	b->signForm(*f);
    	std::cout << *f;
    	b->executeForm(*f);
    	delete b;
    	delete f;
  	}
	catch (std::exception& e)
	{
    	std::cerr << e.what() << "\n";
  	}

  	std::cout << "\n** TEST 4 **\n";
  	try
	{
    	b = new Bureaucrat("Kátia", 150);
    	f = new PresidentialPardonForm("Katy");
    	b->signForm(*f);
    	std::cout << *f;
    	b->executeForm(*f);
    	delete b;
    	delete f;
  	}
	catch (std::exception& e)
	{
    	std::cerr << e.what() << "\n";
  	}

  	std::cout << "\n** TEST 5 **\n";
  	try
	{
    	b = new Bureaucrat("Graça", 20);
    	f = new PresidentialPardonForm("Grace");
    	b->signForm(*f);
    	std::cout << *f;
    	b->executeForm(*f);
    	delete b;
    	delete f;
  	}
	catch (std::exception& e)
	{
    	std::cerr << e.what() << "\n";
  	}

  	std::cout << "\n";

  	return (0);
}
