/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azamario <azamario@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 11:41:57 by azamario          #+#    #+#             */
/*   Updated: 2023/06/12 21:25:05 by azamario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main(void)
{
	Bureaucrat* b;
  	Intern i;
  	AForm* f;

  	std::cout << "\nTESTE 1\n";
  	try
	{
		b = new Bureaucrat("Kátia", 1);
    	f = i.makeForm("Shrubbery Creation Form", "Katy");
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

  	std::cout << "\nTESTE 2\n";
  	try
	{
    	b = new Bureaucrat("João", 1);
    	f = i.makeForm("Robotomy Request Form", "Jhon");
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

  	std::cout << "\nTESTE 3\n";
  	try
	{
    	b = new Bureaucrat("Maria", 1);
    	f = i.makeForm("Presidential Pardon Form", "Mary");
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

  	std::cout << "\nTESTE 4\n";
  	try
	{
		b = new Bureaucrat("Carolina", 150);
    	f = i.makeForm("Crazy Form", "Caroline");
    	b->signForm(*f);
    	std::cout << *f;
    	b->executeForm(*f);
    	delete b;
    	delete f;
  	}
	catch (std::exception& e)
	{
    	std::cerr << e.what() << "\n";
    	delete b;
  	}

  	std::cout << "\nTESTE 5\n";
  	try
	{
    	b = new Bureaucrat("Marco", 150);
    	f = i.makeForm("Presidential Pardon Form", "Mark");
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

  	std::cout << "\nTESTE 6\n";
  	try
	{
    	b = new Bureaucrat("Bob", 20);
    	f = i.makeForm("Presidential Pardon Form", "Bobbie");
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
