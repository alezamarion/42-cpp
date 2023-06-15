/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azamario <azamario@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 12:42:01 by azamario          #+#    #+#             */
/*   Updated: 2023/06/14 23:59:38 by azamario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main( void )
{
    Data       data;
    Data      *deserialized = NULL;
    uintptr_t  serialized;

    std::cout << "\n-------- Original Data: --------\n" << std::endl;
    Serializer::calculateRectangleArea(&data);
    std::cout << data << std::endl;
    
    std::cout << "\n------- Serialized Data: -------\n" << std::endl;
    serialized = Serializer::serialize(&data);
	std::cout << serialized << std::endl;

    std::cout << "\n------ Deserialized Data: ------\n" << std::endl;
    deserialized = Serializer::deserialize(serialized);    
    std::cout << *deserialized << std::endl;
    
    return (0);
}
