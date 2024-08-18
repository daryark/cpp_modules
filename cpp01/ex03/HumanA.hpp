/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 23:24:26 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/08/19 00:29:17 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Weapon.hpp"

class HumanA
{
    private:
        std::string m_name;
        Weapon      &m_weapon;

    public:
        HumanA(std::string name, Weapon& weapon);
        ~HumanA();
        void    attack();
};
