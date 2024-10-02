/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 15:33:35 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/09/17 18:37:16 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
    _type = "Dog 🐕";
    std::cout << BLUE << _type << RE
    << " default constructor" << std::endl;
}

Dog::~Dog()
{
    std::cout << BLUE << _type <<  RE
    << " destructor" << std::endl;
}

Dog::Dog(const Dog& other): Animal()
{
    if (this != &other)
        *this = other;
    std::cout << BLUE << _type << RE
    << " copy constuctor" << std::endl;
}

Dog& Dog::operator=(const Dog& other)
{
    Animal::operator=(other);
    std::cout << BLUE << _type << RE
    << " copy assignment operator" << std::endl;
    return (*this);
}

void    Dog::makeSound() const
{
    std::cout << BLUE << "Bark 🐕" << RE << std::endl;
}

void    Dog::onlyDogCanDo() const
{
    std::cout << "only dog can do" << std::endl;
}