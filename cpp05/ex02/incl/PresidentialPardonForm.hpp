/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 14:19:03 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/12/27 03:45:05 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "../../../colors.hpp"
#include "AForm.hpp"

class PresidentialPardonForm: public AForm
{
private:
    std::string _target;
    void        action()    const;

public:
    PresidentialPardonForm();
    PresidentialPardonForm(std::string _target);
    ~PresidentialPardonForm();

    PresidentialPardonForm(const PresidentialPardonForm& other);
    PresidentialPardonForm& operator=(const PresidentialPardonForm& other);

    const std::string   getTarget() const;

};
