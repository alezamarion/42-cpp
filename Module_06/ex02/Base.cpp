/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azamario <azamario@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 11:59:41 by azamario          #+#    #+#             */
/*   Updated: 2023/05/15 12:00:44 by azamario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

Base* generate( void )
{
  srand(clock());

	switch (rand() % 3)
	{
		case 0 : return (new A);
		case 1 : return (new B);
		case 2 : return (new C);

		default: return (NULL);
	}
}

void identify( Base *p )
{
  if (dynamic_cast<A*>(p))
    std::cout << "Object pointer of type A" << std::endl;

  else if (dynamic_cast<B*>(p))
    std::cout << "Object pointer of type B" << std::endl;

  else if (dynamic_cast<C*>(p))
    std::cout << "Object pointer of type C" << std::endl;

	else
		std::cout << "Object not of type A, B or C" << std::endl;
}

void identify( Base &p )
{
  try 
	{
		A a = dynamic_cast<A&>(p);
		
		std::cout << "Object reference of type A" << std::endl;
	}
	catch (std::exception &excep)
	{
		std::cout << "catch A: " << excep.what() << std::endl;
	}

	try 
	{
		B b = dynamic_cast<B&>(p);
		
		std::cout << "Object reference of type B" << std::endl;
	}
	catch (std::exception &excep)
	{
		std::cout << "catch B: " << excep.what() << std::endl;
	}

	try 
	{
		C c = dynamic_cast<C&>(p);
		
		std::cout << "Object reference of type C" << std::endl;
	}
	catch (std::exception &excep)
	{
		std::cout << "catch C: " << excep.what() << std::endl;
	}
}
