/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 13:59:58 by dyarkovs          #+#    #+#             */
/*   Updated: 2025/01/05 07:03:08 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib> //rand fn
#include <ctime> //srand fn (gives new arg for rand)
#include "../colors.hpp"
#include "Array.hpp"

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
    } //* if the program doesn't core dump here, Then the copy is deap, all clean!

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

     // Test default constructor
    Array<int> a;
    std::cout << "Size of a: " << a.size() << std::endl;

    // Test constructor with size
    Array<int> b(5);
    std::cout << "Size of b: " << b.size() << std::endl;
    //Fill values
    for (unsigned int i = 0; i < b.size(); i++)
        b[i] = i;
    //copy
    a = b;
    //Test operator[] and values
    for (unsigned int i = 0; i < a.size(); i++)
        std::cout << MAGENTA << a[i] << RE << std::endl;
    std::cout << "Size of a: " << a.size() << std::endl;
    
    return 0;
}