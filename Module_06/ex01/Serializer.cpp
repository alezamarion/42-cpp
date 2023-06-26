/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azamario <azamario@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 11:37:22 by azamario          #+#    #+#             */
/*   Updated: 2023/06/26 12:27:19 by azamario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Data::Data(void) :length(10), width(20), area(0)
{
    return;
}

Serializer::Serializer(void)
{
    return;
}

Serializer::Serializer(const Serializer& src)
{
    (void)src;
}

Serializer::~Serializer(void)
{
    std::cout << "Destructor called";
    return;
}

Serializer& Serializer::operator=(const Serializer& rhs)
{
    std::cout << "Copy constructor called";
    (void)rhs;
    return (*this);
}
    
void Serializer::calculateRectangleArea(Data* data)
{
	data->area = data->length * data->width;
    return;
	
}

uintptr_t Serializer::serialize(Data* ptr)
{
    return(reinterpret_cast<uintptr_t>(ptr));
}

Data* Serializer::deserialize(uintptr_t raw)
{
    return(reinterpret_cast<Data*>(raw));
}

std::ostream &operator<<(std::ostream &outputStream, const Data &data)
{
    outputStream << "Length: " << data.length << " Width: " << data.width << " Area: " << data.area << "\n";
    return(outputStream); 
}
