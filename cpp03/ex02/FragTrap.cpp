/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 21:33:10 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/09/07 23:24:21 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

// FragTrap::FragTrap()
// {
//     _health = 100;
//     _energy = 100;
//     _attack = 30;
//     std::cout << "GREEN" << "FragTrap" << RE
//     << " default constructor called"<< std::endl;
// }

// FragTrap::FragTrap(std::string name): ClapTrap(name)
// {
//     _health = 100;
//     _energy = 100;
//     _attack = 30;
//     std::cout << "GREEN" << "FragTrap " << RE 
//     << _name << " constructor called" << std::endl;
// }

// FragTrap::FragTrap(const FragTrap& other)
// {
//     (void)other; //as soon as no new variables added, parent (ClapTrap) copy constructor will work for all
//     std::cout << "FragTrap copy constructor called" << std::endl; 
// }

// FragTrap&   FragTrap::operator=(const FragTrap& other)
// {
//     (void)other; //as soon as no new variables added, parent (ClapTrap) copy constructor will work for all
//     std::cout << "FragTrap copy assignment operator called" << std::endl; 
// }

FragTrap::FragTrap()
{
    _health = 100;
    _energy = 20;
    _attack = 10;
    std::cout << YELLOW << "FragTrap" << RE
    << " default constructor init" << std::endl;
}

FragTrap::FragTrap(std::string name): ClapTrap(name)
{
    _health = 100;
    _energy = 20;
    _attack = 10;
    std::cout << YELLOW << "FragTrap " << RE << _name
    << " constructor init" << std::endl;
}

FragTrap::~FragTrap()
{
    std::cout << YELLOW << "FragTrap" << RE
    << " destructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap& other):  ClapTrap(other._name)
{
    *this = other;
    std::cout << YELLOW << "FragTrap" << RE
    << " copy constructor called" << std::endl;
}

FragTrap&   FragTrap::operator=(const FragTrap& other)
{
    if (this != &other)
        ClapTrap::operator=(other);
    std::cout << YELLOW << "FragTrap" << RE
    << " copy assignment operator called" << std::endl;
    return (*this);
}

void    FragTrap::highFivesGuys()
{
    std::cout << YELLOW << "FragTrap " << RE
    << _name << " requests a high five! 🙌";
    if (_health < 1)
       std::cout << " It's the last thing you can do for him, as he died";
    std::cout << std::endl;
}


