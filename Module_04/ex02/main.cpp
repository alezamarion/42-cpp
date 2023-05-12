/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azamario <azamario@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 14:29:04 by azamario          #+#    #+#             */
/*   Updated: 2023/05/12 14:29:11 by azamario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include "Brain.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main (void)
{
    Cat *cat = new Cat();
    const AAnimal *animals[6];
  //  const AAnimal animal; // Objeto da classe abstrata tipo "AAnimal" não é permitido

    std::cout << "**|Brain: |**\n";
    std::cout << *cat->getBrain();
    std:: cout << "\n";
    delete cat;
    std:: cout << "\n";

    std::cout << "**|Dog - Constructors: |**\n";
    for (int i = 0; i < 3; i++)
    {
        animals[i] = new Dog();
    }
    
    std::cout << "\n**|Cat - Constructors: **|\n";
    for (int i = 3; i < 6; i++)
    {
        animals[i] = new Cat();
    }

    std::cout << "\n**Dog - Destructors: **\n";
    for (int i = 0; i < 3; i++)
    {
        delete animals[i];
    }

    std::cout << "\n**Cat - Destructors: **\n";
    for (int i = 3; i < 6; i++)
    {
        delete animals[i];
    }

    return(0);
}
