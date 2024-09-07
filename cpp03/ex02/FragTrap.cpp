/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 21:33:10 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/09/07 22:09:07 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap()
{
    _health = 100;
    _energy = 100;
    _attack = 30;
    std::cout << "GREEN" << "FragTrap" << RE
    << " default constructor called"<< std::endl;
}

FragTrap::FragTrap(std::string name): ClapTrap(name)
{
    _health = 100;
    _energy = 100;
    _attack = 30;
    std::cout << "GREEN" << "FragTrap " << RE 
    << _name << " constructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap& other)
{
    (void)other; //as soon as no new variables added, parent (ClapTrap) copy constructor will work for all
    std::cout << "FragTrap copy constructor called" << std::endl; 
}

FragTrap&   FragTrap::operator=(const FragTrap& other)
{
    (void)other; //as soon as no new variables added, parent (ClapTrap) copy constructor will work for all
    std::cout << "FragTrap copy assignment operator called" << std::endl; 
}


