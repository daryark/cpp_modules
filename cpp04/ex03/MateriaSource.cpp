/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 22:06:22 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/09/17 03:24:31 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
    std::cout << "MateriaSource  consturctor" << std::endl;
    for (int i = 0; i < INVENTORY_SIZE; i++)
		_inventory[i] = NULL;
}

MateriaSource::~MateriaSource()
{
    for (int i = 0; i < INVENTORY_SIZE; i++)
	{
		if (_inventory[i])
		{
			std::cout << GREEN << "MateriaSource cleaned slot " << i << " of " << this->_inventory[i]->getType() << RE << std::endl;
			delete _inventory[i];
		}
	}
    std::cout << "MateriaSource  destructor" << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource& other)
{
    if (this != &other)
        *this = other;
    std::cout << "MateriaSource  copy constructor" << std::endl;
}

MateriaSource&   MateriaSource::operator=(const MateriaSource& other)
{
    std::cout << "operator=\n";
    if (this != &other)
	{
		for (int i = 0; i < INVENTORY_SIZE; i++)
		{
			if (_inventory[i])
			{
				delete _inventory[i];
				_inventory[i] = NULL;
			}
			if (other._inventory[i])
			{
				_inventory[i] = other._inventory[i]->clone();
				std::cout << "construct inventory on " << i << std::endl;
				std::cout << MAGENTA << _inventory[i]->getType() << RE << std::endl;
			}
		}
	}
	else
		std::cout << "the same object\n";
    std::cout << "MateriaSource  copy assignment operator" << std::endl;
    return (*this);
}

void        MateriaSource::learnMateria(AMateria* m)
{
    for (int i = 0; i < INVENTORY_SIZE; i++)
    {
        if (!_inventory[i])
        {
            _inventory[i] = m->clone();
            return ;
        }
    }
    std::cerr << RED << "No slots left to learn materia" << RE << std::endl;
}

AMateria*   MateriaSource::createMateria(const std::string& type)
{
    for (int i = 0; i < INVENTORY_SIZE; i++)
    {
        if (_inventory[i] && _inventory[i]->getType() == type)
            return (_inventory[i]);
    }
    std::cout << RED << "No inventory with type " << type << RE << std::endl;
    return (NULL);
}
