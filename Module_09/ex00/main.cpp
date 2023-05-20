/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azamario <azamario@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 08:52:17 by azamario          #+#    #+#             */
/*   Updated: 2023/05/20 19:50:57 by azamario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main( int argc, char *argv[] )
{
    if (argc != 2)
    {
        std::cout << "Usage: btc <filename>" << std::endl;
        return (1);
    }

    std::string csvFileName;
    std::string txtFileName;

    csvFileName = "data.csv";
    txtFileName = argv[1];

    bitcoinExchange(csvFileName, txtFileName);

    return (0);
}
