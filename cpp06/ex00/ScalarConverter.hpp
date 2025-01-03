/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 03:39:09 by dyarkovs          #+#    #+#             */
/*   Updated: 2025/01/04 00:18:07 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

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
