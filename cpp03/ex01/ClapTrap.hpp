/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 21:24:45 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/09/07 18:19:29 by dyarkovs         ###   ########.fr       */
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
protected:
    std::string         _name;
    unsigned int        _health; //hit points
    unsigned int        _energy;
    unsigned int        _attack;
    bool                checkPrintDead() const;
public:
    ClapTrap();
    ClapTrap(std::string name);
    ~ClapTrap();
    ClapTrap(const ClapTrap& other);
    ClapTrap&           operator=(const ClapTrap& other);
    void                attack(const std::string& target);
    void                takeDamage(unsigned int amount);
    void                beRepaired(unsigned int amount);
    void                stats() const;
};
