/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azamario <azamario@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 11:19:23 by azamario          #+#    #+#             */
/*   Updated: 2023/05/15 11:40:18 by azamario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <fstream>

class ShrubberyCreationForm : public AForm
{
  private:

    std::string _target;

  public:

    ShrubberyCreationForm( void );
    ShrubberyCreationForm( std::string &target );
    ShrubberyCreationForm( const ShrubberyCreationForm &source );
    ~ShrubberyCreationForm( void );

    ShrubberyCreationForm &operator=( const ShrubberyCreationForm &rhs );

    bool execute( const Bureaucrat &executor ) const;
};

#endif
