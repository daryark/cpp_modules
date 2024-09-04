/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 21:24:26 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/09/04 16:29:51 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(): _name("noname"), _health(10), _energy(10), _attack(0)
{
    std::cout << BLUE << "ClapTrap " << RE << _name << " constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name): _name(name), _health(10), _energy(10), _attack(0)
{
    std::cout << BLUE << "ClapTrap " << RE << _name << " constructor called" << std::endl;
}

ClapTrap::~ClapTrap()
{
    std::cout << BLUE << "ClapTrap " << RE << _name << " destructor called" << std::endl;
}

void    ClapTrap::attack(const std::string& target)
{
    std::cout << BLUE << "ClapTrap " << RE << YELLOW << _name << " attacks " << target
    << " causing " << _attack << " points of damage!" << RE << std::endl;
}

void    ClapTrap::takeDamage(unsigned int amount)
{
    this->_energy -= amount;
    std::cout << BLUE << "ClapTrap " << RE << RED << _name << " takes "
    << amount << " points of damage!" << RE  << std::endl;
}

void    ClapTrap::beRepaired(unsigned int amount)
{
    this->_health += amount;
    std::cout << BLUE << "ClapTrap " << RE << GREEN << _name << " get "
    << amount << " health back!" << RE << std::endl;
}

const std::string&    ClapTrap::getName()
{
    return (this->_name);
}

void    ClapTrap::setName(std::string& s)
{
    this->_name = s;
}