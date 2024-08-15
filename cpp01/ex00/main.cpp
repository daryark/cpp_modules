/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 21:25:11 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/08/15 21:48:59 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
    Zombie  z;
    z.announce();
    
    Zombie *allocated = z.newZombie("Vasya");
    allocated->announce();

    z.randomChump("random");

    delete allocated;
    return (0);
}