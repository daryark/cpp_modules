/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 18:05:41 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/09/09 18:11:55 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ClapTrap.hpp"

class ScavTrap: virtual public ClapTrap
{
    public:
        ScavTrap();
        ScavTrap(std::string name);
        ~ScavTrap(); 
        ScavTrap(const ScavTrap& other);
        ScavTrap&   operator=(const ScavTrap& other);
        void        attack(const std::string &target);
        void        guardGate();
    protected:
        void        setEnergyDefault();
};
