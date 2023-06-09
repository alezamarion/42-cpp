/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azamario <azamario@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 12:40:58 by azamario          #+#    #+#             */
/*   Updated: 2023/06/09 17:29:00 by azamario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
    Animal* animal = new Animal();
    Animal* dog = new Dog();
    Animal* cat = new Cat();
    WrongAnimal* wrongAnimal = new WrongAnimal();
    WrongAnimal* wrongCat = new WrongCat();

    std::cout << "\n1: TYPE" << std::endl;
    std::cout << dog->getType() << " " << std::endl;
    std::cout << cat->getType() << " " << std::endl;
    std::cout << animal->getType() << " " << std::endl;
    std::cout << wrongAnimal->getType() << " " << std::endl;
    std::cout << wrongCat->getType() << " " << std::endl;
    
    std::cout << "\n2: MAKE SOUND" << std::endl;
    std::cout << *dog << " - "; dog->makeSound();
    std::cout << *cat << " - "; cat->makeSound();
    std::cout << *animal << " - "; animal->makeSound();
    std::cout << *wrongAnimal << " - "; wrongAnimal->makeSound();
    std::cout << *wrongCat << " - "; wrongCat->makeSound();
    std::cout << "\n";

	std::cout << "\n3: DELETE" << std::endl;
    delete animal;
    delete dog;
    delete cat;
    delete wrongAnimal;
    delete wrongCat;

    return 0;
}
