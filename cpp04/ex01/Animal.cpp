/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 15:32:19 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/09/13 15:31:19 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal():_type("default_type 👾")
{
    std::cout << YELLOW << "Animal" << RE
    << " default constructor" << std::endl;
}

Animal::~Animal()
{
    std::cout << YELLOW << "Animal" <<  RE
    << " destructor" << std::endl;
}

Animal::Animal(const Animal& other)
{
    if (this != &other)
        *this = other;
    std::cout << YELLOW << "Animal" << RE
    << " copy constuctor" << std::endl;
}

Animal& Animal::operator=(const Animal& other)
{
    std::cout << YELLOW << "Animal" << RE
    << " copy assignment operator" << std::endl;
    if (this != &other)
        _type = other._type;
    return (*this);
}

const std::string&    Animal::getType() const
{
    return (_type);
}

void    Animal::makeSound() const
{
    std::cout << YELLOW << "random Animal 🔊" << RE << std::endl;
}