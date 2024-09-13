/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 21:23:45 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/09/13 13:21:51 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{
    ClapTrap Vayne("Vayne");
    ClapTrap Tim("Tim");
    Tim = Vayne;
    ClapTrap Greg(Tim);
    Greg.attack("Yoohoo");
    Tim.attack("Valleee");
    stats(Tim);
    stats(Vayne);
    Vayne.attack("Nick");
    Vayne.beRepaired(4);
    Vayne.attack("Nick");
    Vayne.takeDamage(5);
    Vayne.takeDamage(14);
    Vayne.attack("Bro");
    Vayne.beRepaired(2);
    Vayne.takeDamage(14);
    return(0);
}