/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 15:35:24 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/09/14 00:25:50 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
    _type = "Cat 🐈";
    _brain = new Brain();
    std::cout << MAGENTA << _type << RE
    << " default constructor" << std::endl;
}

Cat::~Cat()
{
    delete _brain;
    std::cout << MAGENTA << _type <<  RE
    << " destructor" << std::endl;
}

Cat::Cat(const Cat& other): AAnimal()
{
    if (this != &other)
        *this = other;
    std::cout << MAGENTA << _type << RE
    << " copy constuctor" << std::endl;
}

Cat& Cat::operator=(const Cat& other)
{
    if (this != &other)
    {
        AAnimal::operator=(other);
        if (this != &other)
            *(_brain) = *(other._brain);
        // std::cout << "address this: " << _brain
        // << ", address other: " << other._brain << std::endl;
    }
    std::cout << MAGENTA << _type << RE
    << " copy assignment operator" << std::endl;
    return (*this);
}

void    Cat::makeSound() const
{
    std::cout << MAGENTA << "Meow 🐈"
    << RE << std::endl;
}

void    Cat::getIdeaByIdx(int idx) const
{
    std::cout << MAGENTA << _type << RE << " get and idea:  "
    << _brain->getIdeaByIdx(idx) << std::endl;
}

void    Cat::setIdeaByIdx(std::string idea, int idx)
{
    _brain->setIdeaByIdx(idea, idx);
}
