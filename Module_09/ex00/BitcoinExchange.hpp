/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azamario <azamario@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 14:13:30 by azamario          #+#    #+#             */
/*   Updated: 2023/06/21 16:56:45 by azamario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <iomanip>
#include <istream>
#include <map>

struct BitcoinExchange
{
    std::map<std::string, double> _map;
};

void        bitcoinExchange(std::string csvFile, std::string txtFile);
void        getBitcoinData(BitcoinExchange &bitcoinData, std::string file);
void        readInputAndExchangeData(BitcoinExchange &bitcoinData, std::string file);
double      exchangeRate(BitcoinExchange bitcoinData, std::string date);
std::string pastDate(std::string date);
bool        ValidDate(const std::string &date);

#endif
