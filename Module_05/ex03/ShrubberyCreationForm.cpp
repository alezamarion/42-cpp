/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azamario <azamario@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 11:19:43 by azamario          #+#    #+#             */
/*   Updated: 2023/06/12 21:19:07 by azamario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm ()
{
    return;
}
    
ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) : AForm ("Shrubbery Creation Form\n ", 145, 137)
{
    this->setTarget(target);
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src) :AForm(src)
{
    *this = src;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
    return;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm& rhs)
{
    this->_target = rhs._target;
    return (*this);
}

const std::string& ShrubberyCreationForm::getTarget(void) const
{
    return (this->_target);          
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
    if(this->getIsFormSigned() == false)
        throw AForm::UnsignedFormException();
    else if (executor.getGrade() > this->getGradeToExecute())
        throw AForm::GradeTooLowException();
    else if (executor.getGrade() <= this->getGradeToExecute())
    {
        std::string fileOutput(this->getTarget() + "_shrubbery");
        std::ofstream ofs(fileOutput.c_str());
        if(ofs.fail())
            throw AForm::FileOutuptException();
        std::string tree =
        "       *       \n"
        "      *o*      \n"
        "     *o*o*     \n"
        "    *o***o*    \n"
        "   *o*****o*   \n"
        "  *o*******o*  \n"
        "       ||      \n"
        "     ======    \n"; 
        ofs << tree;
        ofs.close();
    }
}
