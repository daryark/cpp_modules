/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 14:17:21 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/12/27 03:46:19 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <fstream>
#include "../../../colors.hpp"
#include "AForm.hpp"

class ShrubberyCreationForm: public AForm
{
private:
    std::string _target;
    void        action()    const;

public:
    ShrubberyCreationForm();
    ShrubberyCreationForm(std::string target);
    ~ShrubberyCreationForm();

    ShrubberyCreationForm(const ShrubberyCreationForm& other);
    ShrubberyCreationForm&    operator=(const ShrubberyCreationForm& other);

    const std::string   getTarget() const;

    class NotCreatedFileException: public std::exception
    {
        virtual const char*  what() const throw(); //throw()=noexcept
    };
};
