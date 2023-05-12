/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azamario <azamario@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 13:15:24 by azamario          #+#    #+#             */
/*   Updated: 2023/05/12 13:15:27 by azamario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(void)
{
    std::cout << "Default Constructor called\n";
    std::stringstream ss;
    std::string s;
    
    for (int i = 0; i < 100; i++)
    {
        ss << i + 1 << " ";
        ss >> s;
        this->_ideas[i] = "Idea: " + s;         
    }
}

Brain::Brain(Brain const &src)
{
    std::cout << "Copy Constructor called\n";
    *this = src;
}

Brain::~Brain()
{
    std::cout << "Destructor called\n";
}

Brain &Brain::operator=(Brain const &rhs)
{
    std::cout << "Brain Assignment Operator called\n";
    for (int i = 0; i < 100; i++)
    {
        this->_ideas[i] = rhs.getIdea(i);
    }
    return (*this);
}

std::string Brain::getIdea(int const &in) const
{
    return (this->_ideas[in]);
}
    
void Brain::setIdea(int const &in, std::string const &idea)
{
    this->_ideas[in] = idea; 
}

std::ostream &operator <<(std::ostream &out, Brain const &in)
{
    for(int i = 0; i< 100; i++)
    {
        out << in.getIdea(i) << "\n";
    }
    return (out);
}
