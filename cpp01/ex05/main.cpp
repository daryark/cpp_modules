/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 15:38:41 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/08/19 21:31:09 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <cstdlib>

static void cleanConsole()
{
    if (!std::system("cls"))
        return ;
    std::cout << "\033[2J\033[1;1H";
}

int main(void)
{
    std::string in;
    Harl harl;

    while (true)
    {
        std::cout << "Harl complain level (DEBUG, INFO, WARNING, ERROR):    ";
        getline(std::cin, in);
        cleanConsole();
        if (std::cin.eof())
            exit(0);
        if (in == "EXIT")
            break ;
        harl.complain(in);
    }
    return (0);
}