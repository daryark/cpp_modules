/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 23:38:40 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/08/19 00:29:57 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name): m_name(name)
{
    std::cout << YELLOW << "HumanB constructor called, " << RE << m_name << std::endl;
}

HumanB::~HumanB()
{
    std::cout << m_name << " destructor called" << std::endl;
}

void    HumanB::attack()
{
    std::cout << m_name << " attacks with their " << m_weapon->getType() << std::endl;
}

void    HumanB::setWeapon(Weapon& weapon)
{
    m_weapon = &weapon;
}