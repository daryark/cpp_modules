/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 15:32:19 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/09/13 15:31:19 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal():_type("default_type 👾")
{
    std::cout << YELLOW << "WrongAnimal" << RE
    << " default constructor" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
    std::cout << YELLOW << "WrongAnimal" <<  RE
    << " destructor" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other)
{
    if (this != &other)
        *this = other;
    std::cout << YELLOW << "WrongAnimal" << RE
    << " copy constuctor" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other)
{
    std::cout << YELLOW << "WrongAnimal" << RE
    << " copy assignment operator" << std::endl;
    if (this != &other)
        _type = other._type;
    return (*this);
}

const std::string&    WrongAnimal::getType() const
{
    return (_type);
}

void    WrongAnimal::makeSound() const
{
    std::cout << YELLOW << "random WrongAnimal 🔊" << RE << std::endl;
}