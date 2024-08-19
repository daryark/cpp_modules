/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 14:16:17 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/08/19 21:04:37 by dyarkovs         ###   ########.fr       */
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
    bool        print = false;
    void        (Harl::*fn[4])() = {&Harl::Debug, &Harl::Info, &Harl::Warning, &Harl::Error};
    std::string level_arr[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    for (int i = 0; i < 4; i++)
    {
        if (level_arr[i] == level)
            print = true;
        if (print)
            (this->*fn[i])();
    }
}

// return type; (class method::*fn[4])(takes void params)
// void (Harl::*fn[4])() = ....

