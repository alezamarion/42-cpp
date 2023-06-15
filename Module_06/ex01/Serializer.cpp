/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azamario <azamario@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 11:37:22 by azamario          #+#    #+#             */
/*   Updated: 2023/06/15 00:00:18 by azamario         ###   ########.fr       */
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

/*
	In summary, the serialize function takes a pointer to a Data object and converts its memory address to an unsigned
	integer using reinterpret_cast<uintptr_t>. This allows the memory address to be represented as an integer value, 
	which can be useful for serialization or other scenarios where the memory address needs to be stored or manipulated
	as an integer.
	
	- This function takes a pointer to an object of type Data and returns the memory address of that object as 
		an unsigned integer of type uintptr_t.
	- reinterpret_cast is a C++ casting operator that allows you to convert one pointer type to another, 
		even if the types are unrelated.
		In this case, the reinterpret_cast is used to convert the ptr pointer of type Data* to an unsigned integer 
		of type uintptr_t. It essentially treats the memory address stored in ptr as an integer value.	
	- The uintptr_t type is an unsigned integer type defined in the <cstdint> or <stdint.h> header. 
		It is guaranteed to be able to hold a pointer value without loss of information. By casting the pointer to 
		uintptr_t, the memory address of the Data object is converted to an unsigned integer representation.
	- Finally, the resulting converted value, which is the memory address of the Data object, is returned from the 
		serialize function.
*/

uintptr_t Serializer::serialize(Data* ptr)
{
    return(reinterpret_cast<uintptr_t>(ptr));
}

/*
	In summary, the deserialize function takes an unsigned integer value representing a memory address (raw) and 
	converts it back to a pointer of type Data* using reinterpret_cast<Data*>. This allows you to reconstruct 
	a pointer to a Data object from its serialized representation as an unsigned integer.
	
	- In this case, the reinterpret_cast is used to convert the raw value of type uintptr_t back to a pointer of type 
	Data*. It essentially treats the unsigned integer raw as a memory address and converts it back to a pointer to Data.
	The resulting pointer is then returned from the deserialize function.
*/

Data* Serializer::deserialize(uintptr_t raw)
{
    return(reinterpret_cast<Data*>(raw));
}

std::ostream &operator<<(std::ostream &outputStream, const Data &data)
{
    outputStream << "Length: " << data.length << " Width: " << data.width << " Area: " << data.area << "\n";
    return(outputStream); 
}
