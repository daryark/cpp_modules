/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 15:34:10 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/09/10 19:11:39 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#pragma once
#include "Animal.hpp"

class Dog: public Animal
{
    public:
        Dog();
        ~Dog();
        Dog(const Dog& other);
        Dog&    operator=(const Dog& other);
        void makeSound() const;
};
