/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 14:13:04 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/12/11 19:50:41 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "../colors.hpp"
#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
    private:
        const std::string   _name;
        bool                _is_signed;
        const unsigned int  _sign_grade;
        const unsigned int  _exec_grade;
        void    checkGradeThrowException(unsigned int grade) const;

    public:
        Form();
        Form(std::string name, unsigned int sign_grade, unsigned int exec_grade);
        ~Form();
        Form(const Form& other);
        Form&   operator=(const Form& other);
        std::string     getName()   const;
        bool            getIsSigned()   const;
        unsigned int    getSignGrade()  const;
        unsigned int    getExecGrade()  const;
        void            beSigned(const Bureaucrat& person);

    class GradeTooHighException: public std::exception
    {
        virtual const char* what() const throw();
    };

    class GradeTooLowException: public std::exception
    {
        virtual const char* what()  const throw();
    };
};

std::ostream&   operator<<(std::ostream& os, const Form& form);
