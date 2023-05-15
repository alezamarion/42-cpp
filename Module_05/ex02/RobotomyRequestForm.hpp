/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azamario <azamario@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 11:18:26 by azamario          #+#    #+#             */
/*   Updated: 2023/05/15 11:18:35 by azamario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include <cstdlib>
#include "AForm.hpp"
class RobotomyRequestForm : public AForm
{
    public:
        RobotomyRequestForm(void);
        explicit RobotomyRequestForm(const std::string target);
        RobotomyRequestForm(const RobotomyRequestForm &src);
        virtual ~RobotomyRequestForm(void);

        RobotomyRequestForm &operator=(const RobotomyRequestForm &rhs);

        const std::string &getTarget(void) const;

        void execute(const Bureaucrat &executor) const;
};


#endif
