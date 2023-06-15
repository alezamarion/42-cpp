/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azamario <azamario@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 11:59:41 by azamario          #+#    #+#             */
/*   Updated: 2023/06/15 00:01:36 by azamario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

Base* generate(void)
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

/*
	The purpose of this code is to determine the actual runtime type of the object pointed to by p in 
	a polymorphic class hierarchy. It uses dynamic_cast to perform type checks and provide different behavior 
	based on the actual type of the object.
*/

void identify(Base* p)
{
	if (dynamic_cast<A*>(p))
    	std::cout << "Object type A" << std::endl;
  	else if (dynamic_cast<B*>(p))
    	std::cout << "Object type B" << std::endl;
  	else if (dynamic_cast<C*>(p))
    	std::cout << "Object type C" << std::endl;
	else
		std::cout << "Object not of type A, B or C" << std::endl;
}

/*
	The purpose of this function is to identify the actual derived type of the object being referred to by p 
	using dynamic_cast.

	If the dynamic_cast succeeds (i.e., if p refers to an object of type A or a derived class of A), the object 
	is assigned to a, and the code inside the corresponding try block is executed. 
	
	If the dynamic_cast fails (i.e., if p does not refer to an object of type A or a derived class of A), 
	an exception of type std::bad_cast is thrown. The code inside the corresponding catch block is executed, 
	and the message "catch A: " followed by the exception's error message is printed.
*/

void identify(Base& p)
{
  try 
	{
		A a = dynamic_cast<A&>(p);		
		std::cout << "Object of type A" << std::endl;
	}
	catch (std::exception &excep)
	{
		std::cout << "catch A: " << excep.what() << std::endl;
	}

	try 
	{
		B b = dynamic_cast<B&>(p);
		std::cout << "Object type B" << std::endl;
	}
	catch (std::exception &excep)
	{
		std::cout << "catch B: " << excep.what() << std::endl;
	}

	try 
	{
		C c = dynamic_cast<C&>(p);		
		std::cout << "Object type C" << std::endl;
	}
	catch (std::exception &excep)
	{
		std::cout << "catch C: " << excep.what() << std::endl;
	}
}
