/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 23:11:05 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/08/18 23:41:03 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

#define RED "\033[1;31m"
#define YELLOW "\033[1;33m"
#define GREEN "\033[1;32m"
#define RE "\033[;0m"

class Weapon
{
    private:
        std::string m_type;
    
    public:
        Weapon();
        Weapon(std::string type);
        ~Weapon();
        const std::string&  getType();
        void                setType(std::string type);
};
