/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 14:13:04 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/12/26 20:37:39 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

#include "../../colors.hpp"
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
    private:
        const std::string   _name;
        bool                _is_signed;
        const int           _sign_grade;
        const int           _exec_grade;
    
        void                checkGradeThrowException(int grade);
        virtual void        action() const = 0;

    public:
        AForm();
        AForm(std::string name, int sign_grade, int exec_grade);
        virtual ~AForm();

        AForm(const AForm& other);
        AForm&   operator=(const AForm& other);
        
        std::string     getName()       const;
        bool            getIsSigned()   const;
        int             getSignGrade()  const;
        int             getExecGrade()  const;

        bool            beSigned(Bureaucrat& person);
        void            execute(Bureaucrat const & executor) const;

    class   GradeTooHighException: public std::exception
    {
        public:
            virtual const char* what() const throw(); //throw() = noexcept
    };

    class   GradeTooLowException: public std::exception
    {
        public:
            virtual const char* what()  const throw(); //throw() = noexcept
    };

    class   NotSignedException: public std::exception
    {
        public:
            virtual const char* what() const throw(); //throw() = noexcept
    };
};

std::ostream&   operator<<(std::ostream& os, const AForm& form);
