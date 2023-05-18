/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azamario <azamario@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 20:55:03 by azamario          #+#    #+#             */
/*   Updated: 2023/05/18 15:02:59 by azamario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Array.hpp"
/*
int main(void)
{
    Array<char> a(10);
    Array<int> b(10);
    Array<float> c(10);
    Array<float> x(c);
    Array<std::string> d(5);
    Array<int> e(0);

    std::cout << "*** CHAR ***\n";
    for (size_t i = 0; i < 10; i++)
        a[i] = static_cast<char>(i + 65);
    
    std::cout << a << "\n";

    std::cout << "*** INT ***\n";
    for (size_t i = 0; i < 10; i++)
        b[i] = static_cast<int>(i + 1);

    std::cout << b << "\n";
    
    std::cout << "*** FLOAT ***\n";    
    for (size_t i = 0; i < 10; i++)
        x[i] = static_cast<float>(1.1f + static_cast<float>(i));

     std::cout << x << "\n";

     std::cout << "*** STRING ***\n";

    for (size_t i = 0; i < 5; i++)
        d[i] = std::string("str") + static_cast<char> (i + '0' + 1);
    
    std::cout << d;

    std::cout << "\n";

    std::cout << "*** Out of Range index ***\n";
    try
    {
        e[100];
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what();
    }
    try
    {
        e[-1];
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    return (0);
}


*/

/*
int main(void)
{
    Array<int> a(10);
    Array<char> b(10);
    Array<float> x(10);
    Array<float> c(x);
    Array<std::string> d(5);
    Array<int> h(0);

    std::cout << "[ INT ARRAY ]\n";
    for (size_t i = 0; i < 10; i++)
    {
        a[i] = static_cast<int>(i + 1);
    }
    std::cout << a;

    std::cout << "\n";

    std::cout << "[ CHAR ARRAY ]\n";
    for (size_t i = 0; i < 10; i++)
    {
        b[i] = static_cast<char>(i + 'a');
    }
    std::cout << b;

    std::cout << "\n";

    std::cout << "[ FLOAT ARRAY ]\n";
    for (size_t i = 0; i < 10; i++)
    {
        c[i] = static_cast<float>(1.1f + static_cast<float>(i));
    }
    std::cout << c;

    std::cout << "\n";

    std::cout << "[ STRING ARRAY ]\n";
    for (size_t i = 0; i < 5; i++)
    {
        d[i] = std::string("str") + static_cast<char>(i + '0' + 1);
    }
    std::cout << d;

    std::cout << "\n";

    std::cout << "[ Out of Range INDEX ]\n";
    try
    {
        h[100];
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what();
    }
    try
    {
        h[-1];
    } 
    catch (const std::exception& e)
    {
        std::cerr << e.what();
    }

    return (0);
}
*/
/*

#define MAX_VAL 750
int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;//
    return 0;
}

*/




/*

int main(void)
{
    Array<char> a(10);
    Array<int> b(10);
    Array<float> c(10);
    Array<float> x(c);
    Array<std::string> d(5);
    Array<int> e(0);

    std::cout << "*** CHAR ***\n";
    for (size_t i = 0; i < 10; i++)
        a[i] = static_cast<char>(i + 1);
    
    std::cout << a << "\n";

    std::cout << "*** INT ***\n";
    for (size_t i = 0; i< 10; i++)
        b[i] = static_cast<int>(i + 1);

    std::cout << b << "\n";
    
    std::cout << "*** FLOAT ***\n";    
    for (size_t i = 0; i < 10; i++)
        x[i] = static_cast<float>(1.1f + static_cast<float>(i));

     std::cout << x << "\n";

     std::cout << "*** STRING ***\n";

    for (size_t i = 0; i < 5; i++)
        d[i] = std::string("str") + static_cast<char> (i + '0' + 1);
    
    std::cout << d;

    std::cout << "\n";

    std::cout << "*** Out of Range index ***\n";
    try
    {
        e[100];
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what();
    }
    try
    {
        e[-1];
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    return (0);
}


// #include <iostream>
// #include <Array.hpp>
*/

#define MAX_VAL 750
int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;//
    return 0;
}