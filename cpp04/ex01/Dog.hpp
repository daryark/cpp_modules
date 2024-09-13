/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 15:34:10 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/09/13 23:57:23 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Animal.hpp"
#include "Brain.hpp"

class Dog: public Animal
{
private:
    Brain*  _brain;
public:
    Dog();
    ~Dog();
    Dog(const Dog& other);
    Dog&    operator=(const Dog& other);
    void    makeSound() const;
    void    getIdeaByIdx(int idx) const;
    void    setIdeaByIdx(std::string idea, int idx);
};
