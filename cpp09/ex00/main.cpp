/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 19:23:44 by dyarkovs          #+#    #+#             */
/*   Updated: 2025/06/27 20:47:00 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"


int main(int ac, char** av)
{
    if (ac != 2)
        return  std::cerr << RED << "Error: <filename> <string_to_find> <subst_string>" << RE << std::endl;
    try
    {
        BitcoinExchange data;
        data.exchange(av[1]);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    return 0;
}