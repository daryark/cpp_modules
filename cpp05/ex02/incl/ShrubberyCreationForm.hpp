/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 14:17:21 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/12/26 20:51:16 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <fstream>
// #include <cstring>

#include "AForm.hpp"

class ShrubberyCreationForm: public AForm
{
private:
    std::string _target;
    void    action()    const;

public:
    ShrubberyCreationForm();
    ShrubberyCreationForm(std::string target);
    ~ShrubberyCreationForm();

    ShrubberyCreationForm(const ShrubberyCreationForm& other);
    ShrubberyCreationForm&    operator=(const ShrubberyCreationForm& other);

    class NotCreatedFileException: public std::exception
    {
        virtual const char*  what() const throw(); //throw()=noexcept
    };
};
