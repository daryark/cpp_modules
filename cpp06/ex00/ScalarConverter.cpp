/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 03:38:41 by dyarkovs          #+#    #+#             */
/*   Updated: 2025/01/04 21:18:47 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ScalarConverter.hpp"

//----------------------convertions--------------------------
template <typename T>
static void    castToChar(T t)
{
	if (t >= 0 && t <= 127)
	{
		if (t > 32)
			std::cout << "'" << static_cast<char>(t) << "'" << std::endl;
		else
			std::cout << "Non displayable" << std::endl;
	}
	else
		std::cout << "impossible" << std::endl;
}

template <typename T, typename C>
static void	castToNum(T t)
{
	if (t == 0 || (t >= std::numeric_limits<C>::min() && t <= std::numeric_limits<C>::max()))
	{
		std::cout << std::fixed << std::setprecision(1) << static_cast<C>(t);
		if (typeid(C) == typeid(float))
			std::cout << "f"; 
		std::cout << std::endl;
	} else
		std::cout << "impossible" << std::endl;
}

template <typename T>
static void	printer(T t)
{
	std::cout << "char:	";
	castToChar(t);
	std::cout << "int:	";
	castToNum<T, int>(t);
	std::cout << "float:	";
	castToNum<T, float>(t);
	std::cout << "dobule:	";
	castToNum<T, double>(t);
}

static bool    isSpecType(std::string s)
{
	return s == "+inf" || s == "-inf" || s == "+inff" || s == "-inff" || s == "nan" || s == "nanf";
}

static void    printSpecType(std::string s)
{
	std::cout << "char:	" << "impossible" << std::endl << "int:	" << "impossible" << std::endl;
	if (s[0] == '+')
		std::cout << "float:	+inff" << std::endl << "double:	+inf" << std::endl;
	else if (s[0] == '-')
		std::cout << "float:	-inff" << std::endl << "double:	-inf" << std::endl;
	else
		std::cout << "float:	nanf" << std::endl << "double:	nan" << std::endl;
}

//--------------------------convertor in class method----------------------------------
ScalarConverter::~ScalarConverter()
{
	std::cout << "DESTRUCTOR" << std::endl;
}

void    ScalarConverter::convert(std::string s)
{
	size_t dot = s.find('.');
	if (isSpecType(s))
		printSpecType(s);
	else if (!s[1] && !isdigit(s[0]))
		printer(static_cast<char>(s[0]));
	else if (dot == std::string::npos)
		printer(std::atol(s.c_str()));
	else
		printer(std::atof(s.c_str())); //converts s->double(double size/precise float)
}