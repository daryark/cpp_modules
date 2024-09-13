/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 15:34:55 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/09/13 23:57:42 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Animal.hpp"
#include "Brain.hpp"

class Cat: public Animal
{
private:
    Brain*  _brain;
public:
    Cat();
    ~Cat();
    Cat(const Cat& other);
    Cat&    operator=(const Cat& other);
    void    makeSound() const;
    void    getIdeaByIdx(int idx) const;
    void    setIdeaByIdx(std::string idea, int idx);
};
