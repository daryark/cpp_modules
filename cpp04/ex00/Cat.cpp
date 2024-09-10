/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 15:35:24 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/09/10 19:18:46 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
    _type = "Cat";
    std::cout << YELLOW << "Cat 🐈" << RE
    << " default constructor" << std::endl;
}

Cat::~Cat()
{
    std::cout << YELLOW << "Cat 🐈" <<  RE
    << " destructor" << std::endl;
}

Cat::Cat(const Cat& other): Animal()
{
    *this = other;
    std::cout << YELLOW << "Cat 🐈" << RE
    << " copy constuctor" << std::endl;
}

Cat& Cat::operator=(const Cat& other)
{
    Animal::operator=(other);
    std::cout << YELLOW << "Cat 🐈" << RE
    << " copy assignment operator" << std::endl;
    return (*this);
}

void    Cat::makeSound() const
{
    std::cout << BLUE << "Meow 🐈" << RE << std::endl;
}
