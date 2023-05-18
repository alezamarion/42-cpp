/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azamario <azamario@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 16:50:34 by azamario          #+#    #+#             */
/*   Updated: 2023/05/18 16:50:38 by azamario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_TPP
#define MUTANTSTACK_TPP

#include "MutantStack.hpp"

template <typename T>
MutantStack<T>::MutantStack(const MutantStack<T>& src) : std::stack<T>()
{
    *this = src;
};

template <typename T>
MutantStack<T>& MutantStack<T>::operator=(const MutantStack<T>& rhs)
{
    std::stack<T>::operator=(rhs);
    return (*this);
};     

#endif
