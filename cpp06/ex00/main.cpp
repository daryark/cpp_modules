/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 16:51:40 by dyarkovs          #+#    #+#             */
/*   Updated: 2025/01/02 15:42:36 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../colors.hpp"
#include "ScalarConverter.hpp"

int main(int ac, char** av)
{
    if (ac != 2)
    {
        std::cerr << U_RED << "Write exactly one argument to convert!" << RE << std::endl;
        return 1;
    }
    ScalarConverter::convert(av[1]);
    return 0;
}
