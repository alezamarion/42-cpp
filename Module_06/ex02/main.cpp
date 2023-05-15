/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azamario <azamario@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 12:02:19 by azamario          #+#    #+#             */
/*   Updated: 2023/05/15 12:04:21 by azamario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

/*

int main(void)
{
    std::cout << "[ CLASS A ]\n";
    A *a = new A();
    identify(a);
    identify(*a);
    delete a;

    std::cout << "\n";

    std::cout << "[ CLASS B ]\n";
    B *b = new B();
    identify(b);
    identify(*b);
    delete b;

    std::cout << "\n";

    std::cout << "[ CLASS C ]\n";
    C *c = new C();
    identify(c);
    identify(*c);
    delete c;

    std::cout << "\n";

    std::cout << "[ CLASS INVALID ]\n";
    Base *base = new Base();
    identify(base);
    identify(*base);
    delete base;

    std::cout << "\n";

    std::cout << "[ RANDOM CLASS]\n";
    Base *random = generate();
    identify(random);
    identify(*random);
    delete random;

    return (0);
}

*/

int main( void )
{

  Base*	base;

	for (int i = 0; i < 10; i++)
	{
		std::cout << std::endl;

		base = generate();

		if (!base)
			return (1);

		identify( base );
		identify( *base );

		delete base;
	}
	
	std::cout << std::endl;

	return (0);

}