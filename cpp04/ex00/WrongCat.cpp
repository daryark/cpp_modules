/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 15:35:24 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/09/13 12:26:39 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat()
{
    _type = "WrongCat 🐈";
    std::cout << MAGENTA << _type << RE
    << " default constructor" << std::endl;
}

WrongCat::~WrongCat()
{
    std::cout << MAGENTA << _type <<  RE
    << " destructor" << std::endl;
}

WrongCat::WrongCat(const WrongCat& other): WrongAnimal()
{
    *this = other;
    std::cout << MAGENTA << _type << RE
    << " copy constuctor" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& other)
{
    WrongAnimal::operator=(other);
    std::cout << MAGENTA << _type << RE
    << " copy assignment operator" << std::endl;
    return (*this);
}

void    WrongCat::makeSound() const
{
    std::cout << MAGENTA << "Wrong Cat says Mooooo 🐄"
    << RE << std::endl;
}
