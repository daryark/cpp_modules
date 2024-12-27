/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 23:45:20 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/12/27 02:48:06 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <map>
#include <cctype>
#include "../../colors.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
private:
    AForm*  makeShrubberyForm(std::string target);
    AForm*  makeRobotomyForm(std::string target);
    AForm*  makePresidentalForm(std::string target);
public:
    Intern();
    ~Intern();

    AForm*  makeForm(std::string form_name, std::string form_taget);

    class FormNameNotFoundException: public std::exception
    {
        public:
            virtual const char* what()  const throw(); //noexcept
    };
};
