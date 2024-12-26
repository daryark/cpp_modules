/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 01:38:30 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/12/24 19:58:58 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string name, int grade): _name(name), _grade(grade)
{
    checkGradeThrowException();
    std::cout << GREEN << _name << " constructor" << RE << std::endl;
};

Bureaucrat::~Bureaucrat()
{
    std::cout << RED << _name << " destructor" << RE << std::endl;
}

//if smth is const in class, you cannot copy it in operator.
//then you create it from scratch once here in copy constructor
Bureaucrat::Bureaucrat(const Bureaucrat& other): _name(other._name)
{
    *this = other;
    std::cout << YELLOW << "Bureaucrat" << RE << " copy constuctor" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
    std::cout << YELLOW << "Bureaucrat" << RE << " copy assignment" << std::endl;
    if (this != &other)
        _grade = other._grade;
    return *this;
}

void    Bureaucrat::increment()
{
    std::cout << "incrementing " << _name << "'s grade " << _grade-- << " by 1" << std::endl;
    checkGradeThrowException();
    std::cout << "now " << _name << "'s grade is " << _grade << std::endl;
}

void    Bureaucrat::decrement()
{
    std::cout << "decrementing " << _name << "'s grade " << _grade++ << " by 1" << std::endl;
    checkGradeThrowException();
    std::cout << "now grade is " << _grade << std::endl;
}

std::string    Bureaucrat::getName()   const
{
    return _name;
}

int    Bureaucrat::getGrade()   const
{
   return _grade;
}

//--------------------Exceptions------------------------
const char* Bureaucrat::GradeTooHighException::what()   const throw()
{
    return  "Grade too high!";
}

const char* Bureaucrat::GradeTooLowException::what()   const throw()
{
    return  "Grade too low!";
}

//--------------------helper stuff------------------------
void    Bureaucrat::checkGradeThrowException()
{
     if (_grade < G_HIGHEST)
        throw Bureaucrat::GradeTooHighException();
    else if(_grade > G_LOWEST)
        throw Bureaucrat::GradeTooLowException();
}

//not in class. but to display/work with class properly
std::ostream&   operator<<(std::ostream& os, const Bureaucrat& instance)
{
    return os << instance.getName() << ", bureaucrat grade " << instance.getGrade() << std::endl;
}