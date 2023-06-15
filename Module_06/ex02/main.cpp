/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azamario <azamario@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 12:02:19 by azamario          #+#    #+#             */
/*   Updated: 2023/06/15 00:02:09 by azamario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

int main( void )
{
	Base*	base;

	for (int i = 0; i < 10; i++)
	{
		std::cout << std::endl;
		base = generate();

		if (!base)
			return (1);

		identify(base);
		identify(*base);

		delete base;
	}	
	std::cout << std::endl;

	return (0);
}
