/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azamario <azamario@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 11:17:56 by azamario          #+#    #+#             */
/*   Updated: 2023/06/12 21:16:26 by azamario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

#include "AForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void) : AForm()
{
    return;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target)
    : AForm("Presidential Pardon Form ", 25, 5)
{
    this->setTarget(target);
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &src) : AForm(src)
{
    *this = src;
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
    return;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &rhs)
{
    this->_target = rhs._target;
    return (*this);
}

const std::string &PresidentialPardonForm::getTarget(void) const
{
    return (this->_target);
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
    if (this->getIsFormSigned() == false)
        throw AForm::UnsignedFormException();
    else if (executor.getGrade() > this->getGradeToExecute())
        throw AForm::GradeTooLowException();
    else if (executor.getGrade() <= this->getGradeToExecute())
        std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox\n";
}
