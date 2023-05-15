/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azamario <azamario@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 11:16:59 by azamario          #+#    #+#             */
/*   Updated: 2023/05/15 11:33:32 by azamario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm( void )
          : _name( "Unknown" ), _signed( false ),
            _gradeToSign( 75 ), _gradeToExecute( 75 )
{
  return ;
}

AForm::AForm( std::string name, int gradeToSign, int gradeToExecute )
          : _name( name ), _signed( false ), _gradeToSign( gradeToSign ),
            _gradeToExecute( gradeToExecute )
{
  if (_gradeToSign < 1 || _gradeToExecute < 1)
    throw GradeTooHighException();

  if (_gradeToSign > 150 || _gradeToExecute > 150)
    throw GradeTooLowException();
  
  return ;
}

AForm::AForm( const AForm &source )
          : _name( source.getName() ), _gradeToSign( source.getGradeToSign() ),
            _gradeToExecute( source.getGradeToExecute() )
{
  *this = source;

  return ;
}

AForm::~AForm( void )
{
  return ;
}

AForm &AForm::operator=( const AForm &rhs )
{
  if (this != &rhs)
    _signed = rhs.isSigned();

  return (*this);
}

std::string AForm::getName( void ) const
{
  return (_name);
}

bool AForm::isSigned( void ) const
{
  return (_signed);
}

int AForm::getGradeToSign( void ) const
{
  return (_gradeToSign);
}

int AForm::getGradeToExecute( void ) const
{
  return (_gradeToExecute);
}

void AForm::beSigned( Bureaucrat &bureaucrat )
{
  if (bureaucrat.getGrade() <= _gradeToSign)
  {
    _signed = true;

    std::cout << bureaucrat.getName() << "'s "
    << _name << " signed." << std::endl;
  }

  else
  {
    std::cout << bureaucrat.getName() << "'s " << _name << " not signed. ";
    
    throw GradeTooLowException();
  }
  return ;
}

std::ostream &operator<<( std::ostream &outputSream, const AForm &form )
{
  outputSream << form.getName();
  outputSream << " Form:";
  outputSream << "\nGrade to sign: ";
  outputSream << form.getGradeToSign();
  outputSream << "\nGrade to execute: ";
  outputSream << form.getGradeToExecute();
  outputSream << "\nSigned: ";

  if (form.isSigned())
    outputSream << "Yes";

  else
    outputSream << "No";

  return (outputSream);
}

bool AForm::execute( Bureaucrat const &executor ) const
{
  if (!_signed)
  {
    throw FormIsNotSignedException();
    
    return (false);
  }

  if (executor.getGrade() > _gradeToExecute)
  {
    throw GradeTooLowException();

    return (false);
  }

  return (true);
}

const char* AForm::GradeTooHighException::what() const throw()
{
  return ("Form exception: grade too high.");
}

const char* AForm::GradeTooLowException::what() const throw()
{
  return ("Form exception: grade too low.");
}

const char* AForm::FormIsNotSignedException::what() const throw()
{
  return ("Form exception: form is not signed.");
}
