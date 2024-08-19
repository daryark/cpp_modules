/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 15:13:04 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/08/19 21:47:32 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

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
    Zombie*             newZombie(std::string name);
    void                randomChump(std::string name);
    const std::string&  getName();
    void                setName(std::string name);
};
