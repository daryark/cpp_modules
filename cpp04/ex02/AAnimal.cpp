/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 15:32:19 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/09/13 19:45:51 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal():_type("default_type 👾")
{
    std::cout << YELLOW << "AAnimal" << RE
    << " default constructor" << std::endl;
}

AAnimal::~AAnimal()
{
    std::cout << YELLOW << "AAnimal" <<  RE
    << " destructor" << std::endl;
}

AAnimal::AAnimal(const AAnimal& other)
{
    if (this != &other)
        *this = other;
    std::cout << YELLOW << "AAnimal" << RE
    << " copy constuctor" << std::endl;
}

AAnimal& AAnimal::operator=(const AAnimal& other)
{
    std::cout << YELLOW << "AAnimal" << RE
    << " copy assignment operator" << std::endl;
    if (this != &other)
        _type = other._type;
    return (*this);
}

const std::string&    AAnimal::getType() const
{
    return (_type);
}
