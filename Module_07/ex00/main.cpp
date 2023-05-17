/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azamario <azamario@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 17:24:07 by azamario          #+#    #+#             */
/*   Updated: 2023/05/17 08:20:18 by azamario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Whatever.hpp"

int main( void ) 
{
    int a = 2;
    int b = 3;

    ::swap( a, b );
    std::cout << "a = " << a << ", b = " << b << std::endl;
 
    //explicit instantiation -> preferred
    std::cout << "min<int>( a, b ) = " << ::min<int>( a, b ) << std::endl; 
    // implicit instantiation -> it might not work for complex classes
    std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl; 

    std::string c = "chaine1";
    std::string d = "chaine2";

    ::swap(c, d);
    std::cout << "c = " << c << ", d = " << d << std::endl;
    std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
    std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;

    return 0;
}

/*

int main( void )
{
    std::cout << std::endl;

    int a = 2;
    int b = 3;

    std::cout << "a = " << a << ", b = " << b << std::endl << std::endl;

    ::swap( a, b );

    std::cout << "a = " << a << ", b = " << b << std::endl << std::endl;

    std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
    std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;

    std::cout << std::endl;

    std::string c = "abcdef";
    std::string d = "abcdea";

    std::cout << "c = " << c << ", d = " << d << std::endl << std::endl;

    ::swap(c, d);

    std::cout << "c = " << c << ", d = " << d << std::endl << std::endl;

    std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
    std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;

    std::cout << std::endl;

    return (0);
}

*/

/*

int main(void)
{
    int a = 2;
    int b = 3;

    float x = 10.5;
    float y = 11.5;

    std::cout << "[ BEFORE SWAP INT ]\n";
    std::cout << "a = " << a << ", b = " << b << std::endl;
    ::swap(a, b);
    std::cout << "\n";
    std::cout << "[ AFTER SWAP INT ]\n";
    std::cout << "a = " << a << ", b = " << b << std::endl;

    std::cout << "\n";

    std::cout << "[ BEFORE SWAP FLOAT ]\n";
    std::cout << "x = " << x << ", y = " << y << std::endl;
    ::swap(x, y);
    std::cout << "\n";
    std::cout << "[ AFTER SWAP FLOAT ]\n";
    std::cout << "x = " << x << ", y = " << y << std::endl;

    std::cout << "\n";


    std::cout << "[ MIN INT ]\n";
    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "min( a, b ) = " << ::min(a, b) << std::endl;

    std::cout << "\n";

    std::cout << "[ MAX INT ]\n";
    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "max( a, b ) = " << ::max(a, b) << std::endl;

    std::cout << "\n";

    std::string c = "chaine1";
    std::string d = "chaine2";

    std::cout << "[ BEFORE SWAP STR ]\n";
    std::cout << "c = " << c << ", d = " << d << std::endl;

    std::cout << "\n";

    ::swap(c, d);
    std::cout << "[ AFTER SWAP STR ]\n";
    std::cout << "c = " << c << ", d = " << d << std::endl;

    std::cout << "\n";

    std::cout << "[ MIN STR ]\n";
    std::cout << "c = " << c << ", d = " << d << std::endl;
        std::cout << "min( c, d ) = " << ::min(c, d) << std::endl;

    std::cout << "\n";

    std::cout << "[ MAX STR ]\n";
    std::cout << "c = " << c << ", d = " << d << std::endl;
    std::cout << "max( c, d ) = " << ::max(c, d) << std::endl;
    return (0);
}

*/
