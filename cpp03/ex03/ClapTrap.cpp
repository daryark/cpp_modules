/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 21:24:26 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/09/08 18:25:45 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(): _name("noname"), _health(10), _energy(10), _attack(0)
{
    std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name): _name(name), _health(10), _energy(10), _attack(0)
{
    std::cout << "ClapTrap " << _name << " constructor called" << std::endl;
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap " << _name << " destructor called" << std::endl;
}

//copy constructor
ClapTrap::ClapTrap(const ClapTrap& other)
{
    std::cout << "ClapTrap copy constructor called" << std::endl;
    *this = other;
}

//copy assignment operator
ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
    if (this != &other)
    {
        this->_name = other._name;
        this->_energy = other._energy;
        this->_health = other._health;
        this->_attack = other._attack;
    }
    std::cout << "ClapTrap copy assignment operator called" << std::endl; 
    return (*this);
}

void    ClapTrap::attack(const std::string& target)
{
    if (checkPrintDead())
        return ;
    _energy--;
    std::cout << "ClapTrap " << _name << " attacks " << target
    << " causing " << _attack << " points of damage!"
    << YELLOW << "  ( -1 ⚡)" << RE << std::endl;
}

void    ClapTrap::takeDamage(unsigned int amount)
{
    if (checkPrintDead())
        return ;
    if (_health <= amount)
    {
        _health = 0;
        std::cout << RED;
    }
    else
        _health -= amount;
    std::cout << "ClapTrap " << _name << " takes "
    << amount << " points of damage!" << YELLOW;
    std::cout << "  ( -" << amount << " ⚡)" << RE << std::endl;
}

void    ClapTrap::beRepaired(unsigned int amount)
{
    if (checkPrintDead())
        return ;
    _energy--;
    _health += amount;
    std::cout << "ClapTrap " << _name << " get "
    << amount << " health back!"
    << YELLOW << "  ( -1 ⚡)" << RE << std::endl;
}

bool    ClapTrap::checkPrintDead() const
{
    if (_health < 1 || _energy < 1)
     {
        std::cout << RED << "ClapTrap " << _name << " is dead" << "    ⭕"
        << RE << std::endl;
        return (true);
     }
     return (false);
}

void    ClapTrap::stats() const
{
    std::cout << "\nName: " << _name << "|    ";
    std::cout << "Health:   " << _health << "|    ";
    std::cout << "Energy:   " << _energy << "|    ";
    std::cout << "Attack:   " << _attack << "|    " << std::endl << std::endl;
}
