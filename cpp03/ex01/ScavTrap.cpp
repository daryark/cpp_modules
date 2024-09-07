/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 18:04:38 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/09/07 23:15:09 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
    _health = 100;
    _energy = 20;
    _attack = 10;
    std::cout << BLUE << "ScavTrap" << RE
    << " default constructor init" << std::endl;
}

ScavTrap::ScavTrap(std::string name): ClapTrap(name)
{
    _health = 100;
    _energy = 20;
    _attack = 10;
    std::cout << BLUE << "ScavTrap " << RE << _name
    << " constructor init" << std::endl;
}

ScavTrap::~ScavTrap()
{
    std::cout << BLUE << "ScavTrap" << RE
    << " destructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other):  ClapTrap(other._name)
{
    *this = other;
    std::cout << BLUE << "ScavTrap" << RE
    << " copy constructor called" << std::endl;
}

ScavTrap&   ScavTrap::operator=(const ScavTrap& other)
{
    if (this != &other)
        ClapTrap::operator=(other);
    std::cout << BLUE << "ScavTrap" << RE
    << " copy assignment operator called" << std::endl;
    return (*this);
}

void    ScavTrap::guardGate()
{
    std::cout << BLUE << "ScavTrap " << RE
    << _name << " is now in Gate keeper mode!" << std::endl;
}

void    ScavTrap::attack(const std::string& target)
{
    if (checkPrintDead())
        return ;
    _energy--;
    std::cout << BLUE << "ScavTrap " << RE << _name << " attacks "
    << target << " causing " << _attack << " points of damage!"
    << YELLOW << "  ( -1 ⚡)" << RE << std::endl;
}
