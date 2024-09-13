/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 15:32:46 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/09/13 18:29:44 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#define RED "\033[0;31m"
#define YELLOW "\033[0;33m"
#define GREEN "\033[0;32m"
#define BLUE "\033[0;34m"
#define MAGENTA "\033[0;35m"
#define RE "\033[;0m"
#include <iostream>

class AAnimal
{
    protected:
        std::string _type;
    public:
        AAnimal();
        virtual ~AAnimal();
        AAnimal(const AAnimal& other);
        AAnimal&             operator=(const AAnimal& other);
        const std::string&  getType() const;
        virtual void        makeSound() const = 0;
};
