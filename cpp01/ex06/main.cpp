/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 15:38:41 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/08/19 16:23:45 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <cstdlib>


//!NOT DONE
//!save it to intra also!!!
int main(void)
{
    std::string in;
    Harl harl;

    while (true)
    {
        std::cout << "Harl complain level (DEBUG, INRO, WARNING, ERROR):    ";
        getline(std::cin, in);
        if (std::cin.eof())
            exit(0);
        if (in == "EXIT")
            break ;
        harl.complain(in);
    }
    return (0);
}