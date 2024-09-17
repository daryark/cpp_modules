/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 22:06:41 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/09/17 02:53:40 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "IMateriaSource.hpp"
#include "AMateria.hpp"

#define INVENTORY_SIZE 4

class MateriaSource: public IMateriaSource
{
private:
    AMateria*   _inventory[INVENTORY_SIZE];
public:
    MateriaSource();
    ~MateriaSource();
    MateriaSource(const MateriaSource& other);
    MateriaSource&  operator=(const MateriaSource& other);
    void            learnMateria(AMateria* m);
    AMateria*       createMateria(std::string const & type);
};
