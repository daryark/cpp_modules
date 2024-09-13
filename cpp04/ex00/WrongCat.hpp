/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 15:34:55 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/09/13 15:35:02 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "WrongAnimal.hpp"

class WrongCat: public WrongAnimal
{
public:
        WrongCat();
        ~WrongCat();
        WrongCat(const WrongCat& other);
        WrongCat&    operator=(const WrongCat& other);
        void    makeSound() const;
};

