/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 03:38:41 by dyarkovs          #+#    #+#             */
/*   Updated: 2025/01/03 00:23:34 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <cctype>
#include <cstdlib>

ScalarConverter::~ScalarConverter()
{
    std::cout << "DESTRUCTOR" << std::endl;
}

void    ScalarConverter::convert(std::string s)
{
    std::cout << "CONVERT: " << s << std::endl;
    if (isSpecType(s))
    printSpecType();
    printer("impossible", 2343343434343434, 4.4, 4.4);
    // std::cout << std::atoi(s) << std::endl;
}

bool    isSpecType(std::string s)
{
    return s == "+inf" || s == "-inf" || s == "+inff" || s == "-inff" || s == "nan" || s == "nanf";
}

void    convertToChar(s)
{

}

void    printSpecType(std::string s)
{
    char prefix = "";
    std::string d;
    std::cout << "char: " << "impossible" << std::endl;
    std::cout << "int: " << "impossible" << std::endl;
    if (s[0] == "+" || s[0] == "-")
    {
        prefix = s[0];
        // s = s.substr(1, )
    }
    std::cout << "float: " + prefix + std::
    
    if (s == "nan" || s == "nanf")
    {
        f = "nanf";
        d = "nan";
    }
}


void    printer(char c, int i, float f, double d)
{
    std::cout << "char: " << c << std::endl;
    std::cout << "int: " << i << std::endl;
    std::cout << "float: " << f << std::endl;
    std::cout << "double: " << d << std::endl;
}
