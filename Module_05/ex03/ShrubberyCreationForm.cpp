/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azamario <azamario@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 11:19:43 by azamario          #+#    #+#             */
/*   Updated: 2023/05/15 11:40:04 by azamario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm( void )
  : AForm( "ShrubberyCreationForm", 145, 137 ), _target( "Unknown" )
{
  return ;
}

ShrubberyCreationForm::ShrubberyCreationForm( std::string &target )
  : AForm( "ShrubberyCreationForm", 145, 137 ), _target( target )
{
  return ;
}

ShrubberyCreationForm::ShrubberyCreationForm( const ShrubberyCreationForm &source )
  : AForm( "ShrubberyCreationForm", 145, 137 )
{
  *this = source;

  return ;
}

ShrubberyCreationForm::~ShrubberyCreationForm( void )
{
  return ;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=
                          ( const ShrubberyCreationForm &rhs )
{
  if (this != &rhs)
    _target = rhs._target;

  return (*this);
}

bool ShrubberyCreationForm::execute( const Bureaucrat &executor ) const
{
  if (AForm::execute(executor))
  {
    std::string		fileName = _target + "_shrubbery";
    std::ifstream fileIn("Shrubbery");
    std::ofstream	fileOut(fileName.c_str());

    if (fileIn && fileOut)
    {
      fileOut << fileIn.rdbuf();
      std::cout << executor.getName() << "'s ASCII tree planted! Open file "
      << fileName << " to see it." << std::endl;
    }
    
    fileIn.close();
    fileOut.close();

    return (true);
  }

  return (false);
}
