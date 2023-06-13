/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azamario <azamario@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 11:18:48 by azamario          #+#    #+#             */
/*   Updated: 2023/06/12 21:17:59 by azamario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void) : AForm()
{
    return;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
    : AForm("Robotomy Request Form", 72, 45)
{
    this->setTarget(target);
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src) : AForm(src)
{
    *this = src;
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
    return;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &rhs)
{
    this->_target = rhs._target;
    return (*this);
}

const std::string &RobotomyRequestForm::getTarget(void) const
{
    return (this->_target);
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
    unsigned int seed;
    int randNum = rand_r(&seed) % (10);

    if (this->getIsFormSigned() == false)
        throw AForm::UnsignedFormException();
    else if (executor.getGrade() > this->getGradeToExecute())
        throw AForm::GradeTooLowException();
    else if (executor.getGrade() <= this->getGradeToExecute() && randNum < 5)
    {
        std::cout << "zzzzzzzz\n";
        std::cout << this->getTarget() << " has been robotomized sucessfully\n";
    }
    else if(executor.getGrade() <= this->getGradeToExecute() && randNum >= 5)
    {
        std::cout << "zzzzzzzz\n";
        std::cout << this->getTarget() << " failed to be robotomized\n";
    }
}
