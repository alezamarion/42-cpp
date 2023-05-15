/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azamario <azamario@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 11:16:38 by azamario          #+#    #+#             */
/*   Updated: 2023/05/15 11:16:41 by azamario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <exception>
#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
    public:
        AForm(void);
        AForm(const std::string name, const int gradeSing, const int gradeExec);
        AForm(const AForm &src);
        virtual ~AForm(void);

        AForm				&operator=(const AForm &rhs);

        const std::string	&getName(void) const;
        bool 				getSigned(void) const;
        int 				getGradeToSign(void) const;
        int 				getGradeToExecute(void) const;

        virtual const std::string	&getTarget(void) const;
        void						setTarget(const std::string &Target);

        void				beSigned(const Bureaucrat &brct);

        virtual void		execute(const Bureaucrat &executor) const = 0;            

        class GradeTooHighException : public std::exception
        {
          public:
            const char*		what(void) const throw();
        };
    
        class GradeTooLowException : public std::exception
        {
            public:
                const char*	what(void) const throw();
        };

        class FileOutuptException: public std::exception
        {
            const char*		what(void) const throw();
        };

        class UnsignedFormException : public std::exception
        {
            const char*		what(void) const throw();
        };

    protected:
        const std::string	_target;

    private:
        const std::string	_name;
        bool 				_isFormSigned;
        const int 			_gradeToSign;
        const int 			_gradeToExecute;
};

std::ostream& operator<<(std::ostream& out, const AForm& in);

#endif
