/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azamario <azamario@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 11:41:01 by azamario          #+#    #+#             */
/*   Updated: 2023/05/15 11:41:04 by azamario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

#define TOTAL_FORMS 3

#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

class Intern
{
  private:

    AForm *_makePresidentialPardonForm( std::string target );
    AForm *_makeRobotomyRequestForm( std::string target );
    AForm *_makeShrubberyCreationForm( std::string target );

  public:

    Intern( void );
    Intern( const Intern &source );
    ~Intern( void );

    Intern &operator=( const Intern &rhs );

    AForm *makeForm( std::string name, std::string target );
};

#endif
