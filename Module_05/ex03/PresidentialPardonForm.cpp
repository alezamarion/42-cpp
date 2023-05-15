/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azamario <azamario@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 11:17:56 by azamario          #+#    #+#             */
/*   Updated: 2023/05/15 11:36:34 by azamario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm( void )
  : AForm( "PresidentialPardon", 25, 5 ), _target( "Unknown" )
{
  return ;
}

PresidentialPardonForm::PresidentialPardonForm( std::string target )
  : AForm( "PresidentialPardon", 25, 5 ), _target( target )
{
  return ;
}

PresidentialPardonForm::PresidentialPardonForm
                          ( const PresidentialPardonForm &source )
  : AForm( "PresidentialPardon", 25, 5 )
{
  *this = source;

  return ;
}

PresidentialPardonForm::~PresidentialPardonForm( void )
{
  return ;
}

PresidentialPardonForm &PresidentialPardonForm::operator=
                                ( const PresidentialPardonForm &rhs )
{
  if (this != &rhs)
    _target = rhs._target;

  return (*this);
}

bool PresidentialPardonForm::execute( const Bureaucrat &executor ) const
{
  if (AForm::execute(executor))
  {
    std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;

    return (true);
  }
  
  return (false);
}
