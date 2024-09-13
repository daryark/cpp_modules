/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 21:23:45 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/09/13 13:32:35 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main(void)
{
    ScavTrap Vayne("Vayne");
    ScavTrap Tim(Vayne);
    Tim.attack("Heeeey");
    ScavTrap newTim("newTim");
    Tim = newTim;
    Vayne.attack("Jack");
    Tim.attack("Nick");
    Vayne.beRepaired(4);
    Vayne.attack("Nick");
    Vayne.takeDamage(50);
    stats(Vayne);
    Vayne.takeDamage(55);
    Vayne.takeDamage(55);
    Vayne.takeDamage(55);
    Vayne.guardGate();
    stats(Vayne);
    Tim.takeDamage(100);
    Tim.beRepaired(50);
    return(0);
}
