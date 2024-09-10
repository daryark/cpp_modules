/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 15:33:35 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/09/10 19:23:34 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
    _type = "Dog";
    std::cout << YELLOW << "Dog 🐕" << RE
    << " default constructor" << std::endl;
}

Dog::~Dog()
{
    std::cout << YELLOW << "Dog 🐕" <<  RE
    << " destructor" << std::endl;
}

Dog::Dog(const Dog& other)
{
    if (this != &other)
        *this = other;
    std::cout << YELLOW << "Dog 🐕" << RE
    << " copy constuctor" << std::endl;
}

Dog& Dog::operator=(const Dog& other)
{
    Animal::operator=(other);
    std::cout << YELLOW << "Dog 🐕" << RE
    << " copy assignment operator" << std::endl;
    return (*this);
}

void    Dog::makeSound() const
{
    std::cout << MAGENTA << "Bark 🐕" << RE << std::endl;
}
