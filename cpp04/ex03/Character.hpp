/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 12:07:41 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/10/02 13:27:53 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#define RED "\033[0;31m"
#define YELLOW "\033[0;33m"
#define GREEN "\033[0;32m"
#define BLUE "\033[0;34m"
#define MAGENTA "\033[0;35m"
#define RE "\033[;0m"

#define INVENTORY_SIZE 4

#include <iostream>
#include "AMateria.hpp"
// #include "ICharacter.hpp"
class ICharacter;

class Character: public ICharacter
{
    private:
        std::string _name;
        AMateria*   _inventory[INVENTORY_SIZE];
    public:
        Character(std::string name);
        ~Character();
        Character(const Character& other);
        Character&          operator=(const Character& other);
        const std::string&  getName() const;
        void                equip(AMateria* m);
        void                unequip(int idx);
        void                use(int idx, ICharacter& target);
};
