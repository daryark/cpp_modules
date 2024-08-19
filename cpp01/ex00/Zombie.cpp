/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 15:12:38 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/08/19 21:47:01 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(): m_name("noname"){};

Zombie::Zombie(std::string name): m_name(name){};

Zombie::~Zombie()
{
    std::cout << RED << m_name << RE << ": destructor called" << std::endl;
};

void    Zombie::announce(void)
{
    std::cout << YELLOW << m_name << RE << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void    Zombie::setName(std::string name)
{
    m_name = name;
}