/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 21:23:45 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/09/13 13:36:14 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main(void)
{
    DiamondTrap Vayne("Vayne");
    stats(Vayne);
    Vayne.whoAmI();
    Vayne.attack("Nick");
    DiamondTrap newVayne(Vayne);
    newVayne.whoAmI();
    stats(newVayne);
    DiamondTrap nextVayne("BRO");
    nextVayne = newVayne;
    nextVayne.whoAmI();
    nextVayne.attack("BROOOO");
    stats(nextVayne);
    return(0);
}
