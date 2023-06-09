/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azamario <azamario@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 13:16:38 by azamario          #+#    #+#             */
/*   Updated: 2023/06/09 17:31:32 by azamario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Brain.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main (void)
{

	std::cout << "\nPART O: AM I DOING A SHALLOW COPY?\n" << std::endl;
	
	std::cout << "The Dog basic class must be destroyed at the end of main()" << std::endl;
	Dog basic;
	{
		std::cout << "\nNow the Dog temp class: \n";
		Dog temp = basic;
		std::cout << "\nThis Dog temp class must be destroyed at the end of this scope: " << std::endl;
	}

		
	std::cout << "\nPART 1: IDEAS\n" << std::endl;
    Cat *cat = new Cat();

   	std::cout << "\n**| Brain: |**\n";
    std::cout << *cat->getBrain();
    std:: cout << "\n";
    delete cat;
    std:: cout << "\n";


 	std::cout << "\nPART 2: ARRAY OF ANIMAL OBJECTS\n" << std::endl;
    const Animal *animals[6];

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

	std::cout << "\nNow that Dog basic class is going to be destroyed: " << std::endl;

    return(0);
}
