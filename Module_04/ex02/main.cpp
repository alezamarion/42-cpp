/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azamario <azamario@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 14:29:04 by azamario          #+#    #+#             */
/*   Updated: 2023/06/09 17:33:52 by azamario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include "Brain.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main (void)
{

	std::cout << "\nPART O: Is AAnimal class instanciable?\n" << std::endl;
    //AAnimal animal;
	

	std::cout << "\nPART 1: IDEAS\n" << std::endl;
    Cat *cat = new Cat();

   	std::cout << "\n**| Brain: |**\n";
    std::cout << *cat->getBrain();
    std:: cout << "\n";
    delete cat;
    std:: cout << "\n";


 	std::cout << "\nPART 2: ARRAY OF ANIMAL OBJECTS\n" << std::endl;
    AAnimal *animals[6];

    std::cout << "**| Dog - Constructors: |**\n";
    for (int i = 0; i < 3; i++)
    {
        animals[i] = new Dog();
    }
    
    std::cout << "\n**| Cat - Constructors: |**\n";
    for (int i = 3; i < 6; i++)
    {
        animals[i] = new Cat();
    }

    std::cout << "\n**| Dog - Destructors: |**\n";
    for (int i = 0; i < 3; i++)
    {
        delete animals[i];
    }

    std::cout << "\n**| Cat - Destructors: |**\n";
    for (int i = 3; i < 6; i++)
    {
        delete animals[i];
    }

    return(0);
}
