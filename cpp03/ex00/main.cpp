/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 21:23:45 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/09/07 16:23:27 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{
    ClapTrap Vayne("Vayne");
    Vayne.stats();
    Vayne.attack("Nick");
    Vayne.beRepaired(4);
    Vayne.attack("Nick");
    Vayne.takeDamage(5);
    // Vayne.stats();
    Vayne.takeDamage(14);
    // Vayne.stats();
    Vayne.attack("Bro");
    Vayne.beRepaired(2);
    Vayne.takeDamage(14);

    // Vayne.stats();
    return(0);
}