/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strReplace.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azamario <azamario@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 18:49:50 by azamario          #+#    #+#             */
/*   Updated: 2023/05/23 18:01:13 by azamario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "strReplace.hpp"

/*
  sta::string replaced takes a string (str) and performs a single replacement of a specified substring (oldStr)
  with another string (newStr). It returns the modified string where the replacement has been made. 
  If any of the input strings are empty or if oldStr is not found within str, the original string is returned without
  any modifications. Additionally, during the execution of the function, the intermediate values of strPos and
  strReplaced are printed to the standard output stream for debugging purposes.  
*/


std::string replaced(const std::string& str, const std::string oldStr, const std::string newStr, size_t strPos)
{
    std::string strReplaced;
    
    if(str.empty() || oldStr.empty() || newStr.empty())
        return (str);

    /* If none of the strings are empty, the code proceeds to find the position of the next occurrence of oldStr 
    within str using str.find(oldStr, strPos). The strPos parameter is used to specify the starting position of the search
    within the string. */   
    strPos = str.find(oldStr, strPos);

    /*If strPos is equal to std::string::npos, it means no further occurrences of oldStr were found in the string,
    so the original str is returned.*/
    if(strPos == std::string::npos)
        return (str);
    
    /*If strPos is a valid position, the code extracts the substring from str starting from the beginning and ending 
    at strPos using str.substr(0, strPos). This represents the portion of the original string before the occurrence 
    of oldStr. The extracted substring is assigned to strReplaced */
    strReplaced = str.substr(0, strPos);

    /* The function then appends newStr to strReplaced */
    strReplaced.append (newStr);

    /* Finally, the function appends the remaining portion of str after the occurrence of oldStr
    (excluding oldStr itself) to strReplaced u*/
    strReplaced.append(str.substr(strPos + oldStr.length()));
    return (strReplaced);
}

/*
    std::string replace() function takes a string (str) and replaces all occurrences of another string (oldStr)
    within it with a specified replacement string (newStr). It returns the modified string with the replacements.
    If any of the input strings are empty, or if no occurrences of oldStr are found, the function returns
    the original string without any modifications.    
*/

std::string replace(const std::string& str, const std::string oldStr, const std:: string newStr)
{
    std::string strReplaced;
    
    if(str.empty() || oldStr.empty() || newStr.empty())
        return (str);
    
    /* If none of the strings are empty, the content of str is assigned to strReplaced using strReplaced.assign(str). 
       This ensures that strReplaced initially contains the same content as the input string. */
    strReplaced.assign(str);

    /* The function then searches for the first occurrence of oldStr within strReplaced using strReplaced.find(oldStr).
    The result is stored in the pos variable of type size_t. */
    /* std::find is a function defined inside <algorithm> header file that finds the element in the given range.
    If the value is found in the sequence, the iterator to its position is returned.
    If the value is not found, the iterator to the last position is returned. */
    size_t pos = strReplaced.find(oldStr);

    /* A while loop is used to replace all occurrences of oldStr with newStr within strReplaced. The loop continues as long
    as pos is not equal to std::string::npos, which indicates that no more occurrences of oldStr were found. */
    
    /* By convention, std::string::npos is defined as a value that is not a valid index or position within the string,
    effectively representing the absence of a valid position. It actually means until the end of the string */
    while(pos != std::string::npos)
    {
        //replaced function is called to perform the actual replacement. The result is assigned back to strReplaced.
        strReplaced = replaced(strReplaced, oldStr, newStr, pos);
        
        /* After the replacement, the find function is called again, but this time with an additional argument: 
        pos + newStr.length(). This ensures that the search for the next occurrence of oldStr starts from the position
        immediately after the replacement. The new pos value is updated accordingly. Once the loop finishes and no more
        occurrences of oldStr are found, the modified string (strReplaced) is returned. */
        pos = strReplaced.find(oldStr, pos + newStr.length());
    }
    return (strReplaced);  
}
