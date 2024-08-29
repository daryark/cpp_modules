/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 21:23:45 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/08/29 21:56:29 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{
    ClapTrap Vayne("Vayne");
    Vayne.attack("Nick");
    Vayne.attack("Nick");
    Vayne.beRepaired(4);
    Vayne.attack("Nick");
    Vayne.attack("Nick");
    Vayne.takeDamage(5);
    return(0);
}