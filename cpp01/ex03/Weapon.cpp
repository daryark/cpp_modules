/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 23:27:42 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/08/19 00:07:32 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"


Weapon::Weapon()
{
    std::cout << GREEN << "Weapon constructor" << RE << std::endl;
};

Weapon::Weapon(std::string type)
{
    m_type = type;
    std::cout << GREEN << "Weapon constructor, " << RE << m_type << std::endl;
};

Weapon::~Weapon()
{
    std::cout << RED << "Weapon destructor called" << RE << std::endl;
}

const std::string&  Weapon::getType()
{
    return (m_type);
}

void    Weapon::setType(std::string type)
{
    m_type = type;
}