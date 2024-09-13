/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 15:34:55 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/09/14 00:26:00 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "AAnimal.hpp"
#include "Brain.hpp"

class Cat: public AAnimal
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
