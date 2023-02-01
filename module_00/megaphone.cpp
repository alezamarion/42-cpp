/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azamario <azamario@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 19:21:43 by azamario          #+#    #+#             */
/*   Updated: 2023/02/01 00:57:21 by azamario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
using std::endl;
using std::cout;
using std::toupper;

int		main(int argc, char **argv)
{
	int	i;
	int	j;
	
	i = 1;
	if (argc == 1)
	{
		cout <<"* LOUD AND UNBEARABLE FEEDBACK NOISE *" << endl;
		return (0);
	}
	while (i < argc)
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			cout << (char)(toupper(argv[i][j]));
			j++;
		}
		if (i != argc -1)
			cout << " ";
		i++;
	}
	cout << endl;
	return (0);
}