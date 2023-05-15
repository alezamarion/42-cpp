/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azamario <azamario@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 11:17:56 by azamario          #+#    #+#             */
/*   Updated: 2023/05/15 11:17:59 by azamario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

#include "AForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void) : AForm()
{
    std::cout << "[PresidentialPardonForm:: Constructor called]\n";
    return;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target)
    : AForm("Presidential Pardon Form ", 25, 5)
{
    std::cout << "[PresidentialPardonForm:: Constructor Parametric called]\n";
    this->setTarget(target);
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &src) : AForm(src)
{
    std::cout << "[PresidentialPardonForm:: Copy Constructor called]\n";
    *this = src;
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
    std::cout << "[PresidentialPardonForm:: Destructor called]\n";
    return;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &rhs)
{
    (void)rhs;
    return (*this);
}

const std::string &PresidentialPardonForm::getTarget(void) const
{
    return (this->_target);
}

void PresidentialPardonForm::execute(const Bureaucrat &executor) const
{
    if (this->getSigned() == false)
        throw AForm::UnsignedFormException();
    else if (executor.getGrade() > this->getGradeToExecute())
        throw AForm::GradeTooHighException();
    else if (executor.getGrade() <- this->getGradeToExecute())
        std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox\n";
}
