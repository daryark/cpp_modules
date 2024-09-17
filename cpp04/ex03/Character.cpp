/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 11:50:31 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/09/17 01:56:23 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(std::string name): _name(name)
{
	std::cout << MAGENTA << "Character " << RE << "consturctor" << std::endl;
	for (int i = 0; i < INVENTORY_SIZE; i++)
		_inventory[i] = NULL;
}

Character::~Character()
{
	// for (int i = 0; i < INVENTORY_SIZE; i++)
	// {
	// 	if (_inventory[i])
	// 	{
	// 		std::cout << GREEN << "cleaned slot " << i << " of " << this->getName() << RE << std::endl;
	// 		delete _inventory[i];
	// 	}
	// }
	std::cout << MAGENTA << "Character " << RE << "destructor" << std::endl;
}

Character::Character(const Character& other)
{
	if (this != &other)
		*this = other;
	std::cout << MAGENTA << "Character " << RE << "copy constructor" << std::endl;
}

//*make copy/clone of the same inventory type,
//*so not to take an actual obj on address
Character&  Character::operator=(const Character& other)
{
	if (this != &other)
	{
		_name = other.getName();
		for (int i = 0; i < INVENTORY_SIZE; i++)
		{
			if (_inventory[i])
			{
				// delete _inventory[i];
				_inventory[i] = NULL;
			}
			if (other._inventory[i])
			{
				_inventory[i] = other._inventory[i];
				// _inventory[i] = other._inventory[i]->clone();
				std::cout << "construct inventory on " << i << std::endl;
				std::cout << MAGENTA << _inventory[i]->getType() << RE << std::endl;
			}
		}
	}
	else
		std::cout << "the same object\n";
	std::cout << MAGENTA << "Character " << RE << "copy assignment operator" << std::endl;
	return (*this);
}

const std::string&  Character::getName() const
{
	return (_name);
}

void    Character::equip(AMateria* m)
{
    for (int i = 0; i < INVENTORY_SIZE; i++)
    {
		if (!_inventory[i])
		{
			_inventory[i] = m;
			std::cout << "🎒 equiped No: " << i << std::endl;
			return ;
		}
    }
	// delete m;
	std::cerr << RED << _name << " inventory is already full" << RE << std::endl;
}

void    Character::unequip(int idx)
{
	if (idx < 0 || idx >= INVENTORY_SIZE)
	{
		std::cout << RED << "Wrong idx, inventory has 4 slots (0-3 idxs)" << RE << std::endl;
		return ;
	}
	if (_inventory[idx])
	{
		// delete _inventory[idx]; //pass them from IMateriaSource
		_inventory[idx] = NULL;
		std::cout << "📤 unequiped No:" << idx << std::endl;
		return ;
	}
	std::cerr << RED << _name << " inventory slot " << idx << " is alredy empty" << RE << std::endl;
}

void    Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx >= INVENTORY_SIZE)
	{
		std::cout << RED << "Wrong idx, inventory has 4 slots (0-3 idxs)" << RE << std::endl;
		return ;
	}
	if (_inventory[idx])
		_inventory[idx]->use(target);
	else
		std::cout << YELLOW << "Inventory slot is empty" << RE << std::endl;
}