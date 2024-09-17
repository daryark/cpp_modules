/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 22:59:25 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/09/17 01:33:27 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice(): AMateria("ice")
{
    std::cout << BLUE << "Ice       " << RE << "consturctor" << std::endl; 
}

Ice::~Ice()
{
    std::cout << BLUE << "Ice       " << RE << "destructor" << std::endl;
}

Ice::Ice(const Ice& other): AMateria(other._type)
{
    if (this != &other)
        *this = other;
    std::cout << BLUE << "Ice       " << RE << "copy consturctor" << std::endl;
}

Ice&    Ice::operator=(const Ice& other)
{
    AMateria::operator=(other);
    std::cout << BLUE << "Ice       " << RE << "copy assignment operator" << std::endl;
    return (*this);
}

AMateria*    Ice::clone() const
{
    return(new Ice());
}

void    Ice::use(ICharacter& target)
{
    std::cout << BLUE << _type << RE << " * shoots an ice bolt at "
    << target.getName() << " *" << std::endl;
}

