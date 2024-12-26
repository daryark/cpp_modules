/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 14:17:53 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/12/26 23:14:03 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once


#include <iostream>
#include <cstdlib> //rand fn
#include <ctime> //srand fn (gives new arg for rand)

#include "../../colors.hpp"
#include "AForm.hpp"

class RobotomyRequestForm: public AForm
{
private:
    std::string _target;
    void        action()    const;

public:
    RobotomyRequestForm();
    RobotomyRequestForm(std::string target);
    ~RobotomyRequestForm();

    RobotomyRequestForm(const RobotomyRequestForm& other);
    RobotomyRequestForm&    operator=(const RobotomyRequestForm& other);

    const std::string   getTarget() const;
};