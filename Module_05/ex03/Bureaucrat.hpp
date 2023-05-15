/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azamario <azamario@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 11:15:52 by azamario          #+#    #+#             */
/*   Updated: 2023/05/15 11:35:48 by azamario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>

class AForm;

class Bureaucrat
{
  
  private:

    const std::string _name;
    int               _grade;

  public:

    Bureaucrat( void );
    Bureaucrat( const std::string name, int grade );
    Bureaucrat( const Bureaucrat &source );
    ~Bureaucrat( void );

    Bureaucrat &operator=( const Bureaucrat &rhs );

    std::string getName( void ) const;
    int getGrade( void ) const;

    void upGrade( void );
    void downGrade( void );
    
    void signForm( AForm &form );
    void executeForm(const AForm &form);

    class GradeTooHighException : public std::exception
    {
      public:

        virtual const char* what() const throw();
    };

    class GradeTooLowException : public std::exception
    {
      public:

        virtual const char* what() const throw();
    };
};

#endif

std::ostream &operator<<( std::ostream &outputStream, const Bureaucrat &bureaucrat );
