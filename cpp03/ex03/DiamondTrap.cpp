/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 10:29:32 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/09/10 13:40:44 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(): ClapTrap("noname_clap_name"), _name("noname")
{
    ScavTrap::setEnergyDefault();
    std::cout << MAGENTA << "DiamondTrap " << RE
    << " default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name): ClapTrap(name + "_clap_name"), _name(name)
{
    ScavTrap::setEnergyDefault();
    std::cout << MAGENTA << "DiamondTrap " << RE
    << _name << " consturctor called" << std::endl;
}

DiamondTrap::~DiamondTrap()
{
 std::cout << MAGENTA << "DiamondTrap" << RE
    << " destructor called" << std::endl;   
}

DiamondTrap::DiamondTrap(const DiamondTrap& other): ClapTrap(other), ScavTrap(other), FragTrap(other), _name(other._name)
{
    std::cout << MAGENTA << "DiamondTrap" << RE
    << " copy constructor called" << std::endl;
}

DiamondTrap&    DiamondTrap::operator=(const DiamondTrap& other)
{
    if (this != &other)
    {
        ClapTrap::operator=(other); //none of them:Scav, Frag have additional VARS to copy them explicitly. so ClapTrap op= is enough
        _name = other._name;
    }
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
