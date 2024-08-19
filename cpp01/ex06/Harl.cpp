/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 14:16:17 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/08/19 21:25:34 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl(){};

Harl::~Harl(){};

void    Harl::Debug()
{
    std::cout << GREEN << "[DEBUG]" << RE << std::endl
    << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!\n\n";
}

void    Harl::Info()
{
    std::cout << BLUE << "[INFO]" << RE << std::endl
    << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!\n\n";
}

void    Harl::Warning()
{
    std::cout << YELLOW << "[WARNING]" << RE << std::endl
    << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month.\n\n";
}

void    Harl::Error()
{
    std::cout << RED << "[ERROR]" << RE << std::endl
    << "This is unacceptable! I want to speak to the manager now.\n\n";
}

void    Harl::complain(std::string level)
{
    int         print;
    void        (Harl::*fn[4])() = {&Harl::Debug, &Harl::Info, &Harl::Warning, &Harl::Error};
    std::string level_arr[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    for (int i = 0; i < 4; i++)
    {
        if (level_arr[i] == level)
            print = i;
    }
    switch (print)
    {
    case 0:
        (this->*fn[0])();
        /* fall through */
    case 1:
        (this->*fn[1])();
        /* fall through */
    case 2:
        (this->*fn[2])();
        /* fall through */
    case 3:
        (this->*fn[3])();
        break;
    
    default:
        std::cout << GREY << "[UNKNOWN TYPE ERROR]" << RE << std::endl
        << "Harl disappointed, burger shop disappeared from the map, who to complain now?!\n\n";
    }

}

// return type; (class method::*fn[4])(takes void params)
// void (Harl::*fn[4])() = ....