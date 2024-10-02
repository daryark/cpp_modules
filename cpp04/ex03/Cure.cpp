/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 11:46:52 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/10/02 13:28:11 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure(): AMateria("cure")
{
	std::cout << GREEN << "Cure	  " << RE << "consturctor" << std::endl; 
}

Cure::~Cure()
{
	std::cout << GREEN << "Cure	  " << RE << "destructor" << std::endl;
}

Cure::Cure(const Cure& other): AMateria(other._type)
{
	if (this != &other)
		*this = other;
	std::cout << GREEN << "Cure	  " << RE << "copy consturctor" << std::endl;
}

Cure&    Cure::operator=(const Cure& other)
{
	if (this != &other)
		AMateria::operator=(other);
	std::cout << GREEN << "Cure	  " << RE << "copy assignment operator" << std::endl;
	return (*this);
}

AMateria*    Cure::clone() const
{
	return(new Cure());
}

void    Cure::use(ICharacter& target)
{
    std::cout << GREEN << _type << RE << " * heals " << target.getName()
    << "’s wounds *" << std::endl;
}

