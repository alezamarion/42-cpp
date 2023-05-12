/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azamario <azamario@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 13:14:37 by azamario          #+#    #+#             */
/*   Updated: 2023/05/12 13:15:12 by azamario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>
#include <string>
#include <sstream>

class Brain
{
    public:
        Brain(void);
        Brain(Brain const &src);
        ~Brain(void);

        Brain &operator=(Brain const &rhs);

        std::string getIdea(int const &in) const;
        void setIdea(int const &in, std::string const &idea);

    private:
        std::string _ideas[100];
};

std::ostream &operator<<(std::ostream &out, Brain const &in);

#endif
