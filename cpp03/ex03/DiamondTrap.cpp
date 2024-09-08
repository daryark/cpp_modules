/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 10:29:32 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/09/08 21:20:49 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(): ClapTrap("noname_clap_name"), _name("noname")
{
    _health = FragTrap::_health;
    _energy = ScavTrap::_energy;
    _attack = FragTrap::_attack;
    std::cout << MAGENTA << "DiamondTrap " << RE
    << " default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name): ClapTrap(name + "_clap_name"), _name(name)
{
    _health = FragTrap::_health;
    _energy = ScavTrap::_energy;
    _attack = FragTrap::_attack; 
    std::cout << MAGENTA << "DiamondTrap " << RE
    << _name << " consturctor called" << std::endl;
}

DiamondTrap::~DiamondTrap()
{
 std::cout << MAGENTA << "DiamondTrap" << RE
    << " destructor called" << std::endl;   
}

DiamondTrap::DiamondTrap(const DiamondTrap& other): ScavTrap(other), FragTrap(other), _name(other._name)
{
    std::cout << MAGENTA << "DiamondTrap" << RE
    << " copy constructor called" << std::endl;
}

//*     ClapTrap::operator=(other); 
// no need to do it explicitly in this example
// (as both Scav and Frag copy _name implicitly (_name is only thing i take from Clap)
// and both don't overwrite it,
// BUT it is a good practice to specify all classes from which you take some part EXPLICITLY
// as smth may change later so Frag or Scav modify name, but I still need to take it exacly from Clap!
DiamondTrap&    DiamondTrap::operator=(const DiamondTrap& other)
{
    if (this != &other)
    {
        ClapTrap::operator=(other);
        ScavTrap::operator=(other);
        FragTrap::operator=(other);
    }
    _name = other._name;
    _health = other._health;
    _energy = other._energy;
    _attack = other._attack;
    std::cout << MAGENTA << "DiamondTrap" << RE
    << " copy assignment operator called" << std::endl;
    return (*this);
}

void    DiamondTrap::attack(const std::string &target)
{
    ScavTrap::attack(target);
}

void    DiamondTrap::whoAmI()
{
    std::cout << MAGENTA << "DiamondTrap" << RE << " names are: "
    << _name << ",    " << ClapTrap::_name << std::endl;
}
