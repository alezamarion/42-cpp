/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strReplace.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azamario <azamario@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 18:46:42 by azamario          #+#    #+#             */
/*   Updated: 2023/05/07 18:54:17 by azamario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRREPLACE_HPP
#define STRREPLACE_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

std::string replaced(const std::string& str, const std::string oldStr, const std::string newStr, size_t strPos);
std::string replace(const std::string& str, const std::string oldStr, const std:: string newStr);

#endif