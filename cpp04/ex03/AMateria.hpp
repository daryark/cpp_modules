/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 15:52:00 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/09/15 21:10:32 by dyarkovs         ###   ########.fr       */
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
#include "ICharacter.hpp"

class ICharacter;
class AMateria
{
protected:
    std::string _type;
public:
AMateria(const std::string& type);
virtual ~AMateria();
AMateria(const AMateria& other);
AMateria&           operator=(const AMateria& other);
const std::string&  getType() const; //Returns the materia type
virtual AMateria*   clone() const = 0;
virtual void        use(ICharacter& target);
};
