/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 01:38:30 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/12/10 23:19:24 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string name, unsigned int grade): _name(name), _grade(grade)
{
    std::cout << GREEN << _name << " constructor" << RE << std::endl;
};

Bureaucrat::~Bureaucrat()
{
    std::cout << RED << _name << " destructor" << RE << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other)
{
    *this = other;
    std::cout << YELLOW << "Bureaucrat" << RE << " copy constuctor" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
    if (this != &other)
        _grade = other._grade;
    return *this;
}


void    Bureaucrat::checkGradeThrowException()    const
{
     if (_grade < 1)
        throw Bureaucrat::GradeTooHighException();
    else if(_grade > 150)
        throw Bureaucrat::GradeTooLowException();
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

const char* Bureaucrat::GradeTooHighException::what()   const throw()
{
    return  "Grade too high!";
}

const char* Bureaucrat::GradeTooLowException::what()   const throw()
{
    return  "Grade too low!";
}

//not in class. but to display/work with class properly
std::ostream&   operator<<(std::ostream& os, const Bureaucrat& instance)
{
    return os << instance.getName() << ", bureaucrat grade " << instance.getGrade() << std::endl;
}