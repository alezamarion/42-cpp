/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azamario <azamario@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 16:36:22 by azamario          #+#    #+#             */
/*   Updated: 2023/05/11 17:37:27 by azamario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <string>
#include <iostream>
#include <stdint.h>

struct Data
{
    float length;
    float width; 
    Data(void);
};

class Serializer
{
    public:
        Serializer(void);
        Serializer(const Serializer&);
        ~Serializer(void);

        Serializer& operator=(const Serializer& src);

        float calculateRectangleArea(Data *data);
    
        static uintptr_t serialize(Data* ptr);
        static Data *deserialize(uintptr_t raw);     
};

std::ostream &operator<<(std::ostream &outputStream, const Data &data);

#endif
