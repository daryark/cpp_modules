/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 21:23:45 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/09/08 21:20:53 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main(void)
{
    DiamondTrap Vayne("Vayne");
    Vayne.stats();
    Vayne.whoAmI();
    Vayne.attack("Nick");
    DiamondTrap newVayne(Vayne);
    newVayne.whoAmI();
    newVayne.stats();
    DiamondTrap nextVayne("BRO");
    nextVayne = newVayne;
    nextVayne.whoAmI();
    nextVayne.attack("BROOOO");
    nextVayne.stats();
    return(0);
}
