/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 15:34:10 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/09/14 00:26:16 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "AAnimal.hpp"
#include "Brain.hpp"

class Dog: public AAnimal
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
