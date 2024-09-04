/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 21:24:45 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/09/04 16:25:56 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#define RED "\033[0;31m"
#define YELLOW "\033[0;33m"
#define GREEN "\033[0;32m"
#define BLUE "\033[0;34m"
#define RE "\033[;0m"

#include <iostream>

class ClapTrap
{
private:
    std::string         _name;
    unsigned int        _health;
    unsigned int        _energy;
    const unsigned int  _attack;
public:
    ClapTrap();
    ClapTrap(std::string name);
    ~ClapTrap();
    void                attack(const std::string& target);
    void                takeDamage(unsigned int amount);
    void                beRepaired(unsigned int amount);
    //? do i need getter and setter for this class ??
    const std::string&  getName();
    void                setName(std::string& s);
};