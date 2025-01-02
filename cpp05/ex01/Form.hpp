/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 14:13:04 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/12/27 03:44:30 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "../../colors.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

class Bureaucrat;

class Form
{
    private:
        const std::string   _name;
        bool                _is_signed;
        const int           _sign_grade;
        const int           _exec_grade;
        void    checkGradeThrowException(int grade) const;

    public:
        Form();
        Form(std::string name, int sign_grade, int exec_grade);
        ~Form();
        Form(const Form& other);
        Form&   operator=(const Form& other);
        std::string     getName()   const;
        bool            getIsSigned()   const;
        int             getSignGrade()  const;
        int             getExecGrade()  const;
        bool            beSigned(Bureaucrat& person);

    class GradeTooHighException: public std::exception
    {
        public:
            virtual const char* what() const throw();
    };

    class GradeTooLowException: public std::exception
    {
        public:
            virtual const char* what()  const throw();
    };
};

std::ostream&   operator<<(std::ostream& os, const Form& form);
