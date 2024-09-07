/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 21:23:45 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/09/07 18:18:39 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main(void)
{
    ScavTrap Vayne("Vayne");
    Vayne.attack("Nick");
    Vayne.beRepaired(4);
    Vayne.attack("Nick");
    Vayne.takeDamage(50);
    Vayne.stats();
    Vayne.takeDamage(55);
    Vayne.takeDamage(55);
    Vayne.guardGate();
    Vayne.stats();
    return(0);
}
