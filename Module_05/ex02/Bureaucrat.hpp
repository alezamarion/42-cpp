/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azamario <azamario@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 11:15:52 by azamario          #+#    #+#             */
/*   Updated: 2023/06/12 21:12:33 by azamario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>

#include "AForm.hpp"

class AForm;

class Bureaucrat
{
    public:
        Bureaucrat(void);
        Bureaucrat(const std::string name, const int grade);
        Bureaucrat(const Bureaucrat &src);
        ~Bureaucrat(void);

        Bureaucrat &operator=(Bureaucrat const &rhs);

        const std::string   &getName(void) const;
        int                 getGrade(void) const;
        void                incrementGrade(void);
        void                decrementGrade(void);

        void                signForm(const AForm &form) const;
        void				executeForm(AForm const &form) const;

        class GradeTooHighException : public std::exception
        {
          public:
            const char* what(void) const throw();
        };
    
        class GradeTooLowException : public std::exception
        {
            public:
                const char* what(void) const throw();
        };

    private:
        const std::string _name;
        int _grade;

};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &in);

#endif
