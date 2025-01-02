/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 01:38:48 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/12/27 03:44:24 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#define G_LOWEST    150
#define G_HIGHEST   1

#include <iostream>

#include "../../colors.hpp"
#include "Form.hpp"

class Form;

class Bureaucrat
{
private:
    const std::string   _name;
    int                 _grade;

    Bureaucrat();
    void         checkGradeThrowException();

public:
    Bureaucrat(std::string name, unsigned int grade);
    ~Bureaucrat();
    Bureaucrat(const Bureaucrat& other);
    Bureaucrat& operator=(const Bureaucrat& other);
    std::string getName()   const;
    int         getGrade()  const;
    void        increment();
    void        decrement();
    void        signForm(Form& form);

    class GradeTooHighException: public std::exception
    {
        public:
            virtual const char* what()  const throw();
    };

    class GradeTooLowException: public std::exception
    {
        public:
            virtual const char* what()  const throw();
    };  
};

std::ostream&    operator<<(std::ostream& os, const Bureaucrat& instance);


//* virtual const *char what()  throw() const; 
// virtual - just to be explicit and for potential extention later
// const char* - returns a pointer to not changable(const) c-string(to be lightweight)
// throw() - says that this fn will never throw an exception //later since C++11 "noexcept" word is used instead.
//      So yeah actually throw=noexcept(ions)=> not throw exceptions.
// first const, then throw()/noexcept - as const releates to fn itself and exceptions are consider as a separate aspect by compiler.