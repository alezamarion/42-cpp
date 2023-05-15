/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azamario <azamario@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 11:17:32 by azamario          #+#    #+#             */
/*   Updated: 2023/05/15 11:17:42 by azamario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"
class PresidentialPardonForm : public AForm
{
    public:
        PresidentialPardonForm(void);
        explicit PresidentialPardonForm(const std::string &target);
        PresidentialPardonForm(const PresidentialPardonForm &src);
        virtual ~PresidentialPardonForm(void);

        PresidentialPardonForm &operator=(const PresidentialPardonForm &rhs);

        const std::string &getTarget(void) const;

        void execute(const Bureaucrat &executor) const;
};

#endif
