/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 03:39:09 by dyarkovs          #+#    #+#             */
/*   Updated: 2025/01/05 00:15:02 by dyarkovs         ###   ########.fr       */
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
	ScalarConverter();//=delete(std11) //*to create static, non-instanciable class
	ScalarConverter(const ScalarConverter& other);//=delete(std11) //*bcs of requirement for canonical form
	ScalarConverter&    operator=(const ScalarConverter& other);//=delete(std11) //*bcs of requirement for canonical form
public:
	~ScalarConverter();
	static void convert(std::string s);
};
