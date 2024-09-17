/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 11:49:45 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/09/17 02:04:49 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
// #include "AMateria.hpp"

int main(void)
{
    Ice* ice = new Ice();
    Cure* cure = new Cure();
    std::cout << "==============created me===============\n";
    Character me("ME_1");
    std::cout << me.getName() << std::endl;
    me.equip(ice); //0
    me.equip(ice); //1
    me.equip(cure); //2
    me.equip(ice); //3
    me.equip(ice); //full
    me.use(3, me); //ice
    me.use(5, me); //no idx
    std::cout << "==============created bob===============\n";
    Character bob("BOB_2");
    std::cout << bob.getName() << std::endl;
    bob.use(2, me); //empty slot
    me.use(3, bob); //ice
    bob.unequip(3); //already empty
    bob.unequip(8); //no idx
    std::cout << "===============me is bob==============\n";
    me = bob; // both names now: BOB_2, slots empty as bob had this state
    std::cout << "me " << &me << "  bob " << &bob << std::endl;
    me.unequip(2); //empty
    std::cout << "=============bob================\n";
    bob.equip(ice); //0
    bob.equip(cure); //1
    bob.equip(cure); //2
    std::cout << "=============me================\n";
    me.equip(ice); //0
    me.equip(ice); //1
    std::cout << "=============bob-me/me-bob================\n";
    bob.use(2, me); //cure
    me.use(2, bob); //empty slot
    std::cout << "=============bob================\n";
    bob.unequip(1); //free slot done
    bob.equip(cure); //1
    bob.equip(ice); //3 (as 2 slot is taken with cure, line 46)
    bob.use(0, bob); //ice
    bob.use(1, bob); //cure
    std::cout << "==============me===============\n";
    me.use(0, bob); //ice
    me.use(1, me); //ice
    me.use(2, bob); //empty
    me.use(4, me); //no idx
    bob = me; //only 0,1 slots taken
    std::cout << "me " << &me << "  bob " << &bob << std::endl;
    std::cout << "=============me================\n";
    me.use(0, me); //ice
    me.use(1, bob); //ice
    me.use(2, me); //empty slot
    me.use(3, bob); //empty slot
    std::cout << "=============================\n";
    delete ice;
    delete cure;
    return (0);
}

//?check use for idx in range 0-3