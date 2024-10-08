/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 11:48:54 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/09/15 21:07:56 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ICharacter.hpp"
#include "AMateria.hpp"

class Cure: public AMateria
{
    public:
        Cure();
        ~Cure();
        Cure(const Cure& other);
        Cure&       operator=(const Cure& other);
        AMateria*   clone() const;
        void        use(ICharacter& target);
};
