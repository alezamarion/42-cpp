/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strReplace.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azamario <azamario@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 18:49:50 by azamario          #+#    #+#             */
/*   Updated: 2023/06/26 12:19:48 by azamario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "strReplace.hpp"

std::string replaced(const std::string& str, const std::string oldStr, const std::string newStr, size_t strPos)
{
    std::string strReplaced;
    
    if(str.empty() || oldStr.empty() || newStr.empty())
        return (str);
    strPos = str.find(oldStr, strPos);
    if(strPos == std::string::npos)
        return (str);
    strReplaced = str.substr(0, strPos);
    strReplaced.append (newStr);
    strReplaced.append(str.substr(strPos + oldStr.length()));
    return (strReplaced);
}

std::string replace(const std::string& str, const std::string oldStr, const std:: string newStr)
{
    std::string strReplaced;
    
    if(str.empty() || oldStr.empty() || newStr.empty())
        return (str);    
    strReplaced.assign(str);
    size_t pos = strReplaced.find(oldStr);
    while(pos != std::string::npos)
    {
        strReplaced = replaced(strReplaced, oldStr, newStr, pos);
        pos = strReplaced.find(oldStr, pos + newStr.length());
    }
    return (strReplaced);  
}
