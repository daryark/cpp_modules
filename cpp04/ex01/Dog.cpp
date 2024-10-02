/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 15:33:35 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/09/17 19:07:17 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
    _type = "Dog 🐕";
    _brain = new Brain();
    std::cout << BLUE << _type << RE
    << " default constructor" << std::endl;
}

Dog::~Dog()
{
    delete _brain;
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
    if (this != &other)
    {
        Animal::operator=(other);
        if (this != &other)
            *(_brain) = *(other._brain);
        std::cout << "address this: " << _brain
        << ", address other: " << other._brain << std::endl;
    }
    std::cout << BLUE << _type << RE
    << " copy assignment operator" << std::endl;
    return (*this);
}

void    Dog::makeSound() const
{
    std::cout << BLUE << "Bark 🐕" << RE << std::endl;
}

void    Dog::getIdeaByIdx(int idx) const
{
    std::cout << BLUE << _type << RE << " get and idea:  "
    << _brain->getIdeaByIdx(idx) << std::endl;
}

void    Dog::setIdeaByIdx(std::string idea, int idx)
{
    _brain->setIdeaByIdx(idea, idx);
}