/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 15:13:04 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/08/18 23:19:39 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <sstream>

#define RED "\033[1;31m"
#define YELLOW "\033[1;33m"
#define RE "\033[;0m"



class Zombie
{
private:
    std::string m_name;
public:
    Zombie();
    Zombie(std::string name);
    ~Zombie();
    void                announce(void);
    const std::string&  getName();
    void                setName(std::string name);
};

Zombie* zombieHorde(int N, std::string name);