/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azamario <azamario@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 12:42:01 by azamario          #+#    #+#             */
/*   Updated: 2023/05/11 17:37:17 by azamario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main( void )
{
    Data       data;
    Data      *deserialized = NULL;
    uintptr_t  serialized;

    std::cout << std::endl;
    std::cout << "-------- Original Data: --------" << std::endl;
    std::cout << std::endl;

    std::cout << data << std::endl;
    
    std::cout << std::endl;
    std::cout << "------- Serialized Data: -------" << std::endl;
    std::cout << std::endl;

    serialized = Serializer::serialize( &data );

    std::cout << serialized << std::endl;
    //calculateRectangleArea(&data);

    std::cout << std::endl;
    std::cout << "------ Deserialized Data: ------" << std::endl;
    std::cout << std::endl;

    deserialized = Serializer::deserialize( serialized );
    
    std::cout << *deserialized << std::endl;

    std::cout << std::endl;
    
    return (0);
}