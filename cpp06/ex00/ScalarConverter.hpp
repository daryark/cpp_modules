/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 03:39:09 by dyarkovs          #+#    #+#             */
/*   Updated: 2025/01/05 10:45:08 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <cctype>
#include <cstdlib>
#include <limits> //cpp limits (able to use with templates<>)
#include <iomanip> //setprecision
#include <typeinfo> //typeid
#include "../../colors.hpp"

class ScalarConverter
{
private:
	ScalarConverter(){};//=delete(std11) //? private to create static, non-instanciable class
										//?call fn to not have occasional linker errors. But no need to realize, as soon as never used
	ScalarConverter(const ScalarConverter& other){};//=delete(std11) //*
	ScalarConverter&    operator=(const ScalarConverter& other){};//=delete(std11) //*
public:
	~ScalarConverter();
	static void convert(std::string s);
};
