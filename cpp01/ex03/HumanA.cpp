/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 23:31:27 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/08/19 00:26:34 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& weapon): m_name(name), m_weapon(weapon)
{
    std::cout << YELLOW << "HumanA constructor called, " << RE << m_name << std::endl;
}

HumanA::~HumanA()
{
    std::cout << m_name << " destructor called" << std::endl;
}

void    HumanA::attack()
{
    std::cout << m_name << " attacks with their " << m_weapon.getType() << std::endl;
}
