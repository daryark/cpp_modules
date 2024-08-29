/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 21:24:26 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/08/29 21:57:58 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name): _name(name), _health(10), _energy(10), _attack(0)
{
    std::cout << "ClapTrap " << _name << " constructor called" << std::endl;
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap " << _name << " destructor called" << std::endl;
}

void    ClapTrap::attack(const std::string& target)
{
    std::cout << "ClapTrap " << YELLOW << _name << " attacks " << target
    << " causing " << _attack << " points of damage!" << RE << std::endl;
}

void    ClapTrap::takeDamage(unsigned int amount)
{
    this->_energy -= amount;
    std::cout << "ClapTrap " << RED << _name << " takes "
    << amount << " points of damage!" << RE  << std::endl;
}

void    ClapTrap::beRepaired(unsigned int amount)
{
    this->_health += amount;
    std::cout << "ClapTrap " << GREEN << _name << " get "
    << amount << " health back!" << RE << std::endl;
}
