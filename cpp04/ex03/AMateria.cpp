/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 22:31:17 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/09/15 23:49:21 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(const std::string& type): _type(type)
{
    std::cout << "AMateria  consturctor" << std::endl;
}

AMateria::~AMateria()
{
    std::cout << "AMateria  destructor" << std::endl;
}

AMateria::AMateria(const AMateria& other)
{
    if (this != &other)
        *this = other;
    std::cout << "AMateria  copy constructor" << std::endl;
}

AMateria&   AMateria::operator=(const AMateria& other)
{
    if (this != &other)
        _type = other._type;
    std::cout << "AMateria  copy assignment operator" << std::endl;
    return (*this);
}

const std::string&  AMateria::getType() const
{
    return(_type);
}


void    AMateria::use(ICharacter& target)
{
    std::cout << "Useless for" << target.getName() << std::endl;
}
//to be able to use this fn (use) in Ice and Cube child classes
//this one need to be written, not abstract here,
//but as class overall is abstract, it will never be called or created by itself
//only other classes that inherit from this one can call constuctor
//and so after we can use them as AMateria