/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azamario <azamario@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 19:21:43 by azamario          #+#    #+#             */
/*   Updated: 2023/05/22 10:35:48 by azamario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int		main(int argc, char **argv)
{
	int	i;
	int	j;
	
	i = 1;
	if (argc == 1)
	{
		std::cout <<"* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	while (i < argc)
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			std::cout << (char)(std::toupper(argv[i][j]));
			j++;
		}
		if (i != argc - 1)
			std::cout << " ";
		i++;
	}
	std::cout << std::endl;
	return (0);
}

/*
The main function is the entry point of the program.
It takes two parameters: argc, which represents the number of command-line arguments passed to the program,
and argv, an array of strings containing the arguments themselves.

i and j are integer variables that will be used as loop counters.
i is initialized to 1 because argv[0] usually contains the name of the program itself.

This part uses nested loops to iterate over each command-line argument (argv[i]). 
The outer loop runs from i (initialized to 1) to argc - 1, which covers all the arguments passed.

The inner loop iterates over each character of the current argument (argv[i][j]) 
until it reaches the null terminator ('\0'). 
Inside the loop, it converts each character to uppercase using std::toupper and prints it using std::cout.

Once the inner loop finishes, it checks if i is not equal to argc - 1. 
If that's the case, it means there are more arguments to process, so it prints a space character 
to separate the converted arguments.

Overall, this code takes command-line arguments, converts each argument to uppercase, 
and prints them with spaces in between. 
If no arguments are provided, it prints a specific message instead.
*/