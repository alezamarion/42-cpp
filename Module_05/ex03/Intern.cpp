/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azamario <azamario@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 11:41:19 by azamario          #+#    #+#             */
/*   Updated: 2023/06/12 21:24:30 by azamario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern(void)
{
    return;
}

Intern::Intern(const Intern& src)
{
  	*this = src;
}

Intern::~Intern(void)
{
  	return ;
}

Intern &Intern::operator=(const Intern& rhs)
{
	  (void)rhs;
  	return (*this);
}

AForm *Intern::makeForm(const std::string name, const std::string target)
{
    std::string formType[3] = { "Shrubbery Creation Form", "Robotomy Request Form",
								                "Presidential Pardon Form" };

	  AForm *(Intern::*f[3])(const std::string) const = { &Intern::makeShrubberyCreationForm, 
														                            &Intern::makeRobotomyRequestForm, 
														                            &Intern::makePresidentialPardonForm };

	  for (int i = 0; i < 3; i++)
	  {
		  if (!formType[i].compare(name))
		  {
			  std::cout << "Intern creates " << name << " :D" << std::endl;
			  return ((this->*f[i])(target));
      }
    }
    throw Intern::NoMatchException();
}

AForm* Intern::makePresidentialPardonForm(const std::string target) const
{
	  return (new PresidentialPardonForm(target));
}

AForm* Intern::makeRobotomyRequestForm(const std::string target) const
{
	  return (new RobotomyRequestForm(target));
}

AForm* Intern::makeShrubberyCreationForm(const std::string target) const
{
	  return (new ShrubberyCreationForm(target));
}

AForm* Intern::invalidForm(const std::string target) const
{
	  (void)target;
  	return (NULL);
}

const char* Intern::NoMatchException::what(void) const throw()
{
    return ("This form does not exist! :(");
}
