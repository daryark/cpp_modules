/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 01:38:30 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/12/12 19:23:31 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string name, unsigned int grade): _name(name), _grade(grade)
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
    std::cout << YELLOW << "Bureaucrat" << RE << " copy constuctor" << std::endl;
    *this = other;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
    std::cout << YELLOW << "Bureaucrat" << RE << " copy assignment" << std::endl;
    if (this != &other)
        _grade = other._grade;
    return *this;
}

//-------------------getters----------------------------
std::string Bureaucrat::getName()   const
{
    return _name;
}

int         Bureaucrat::getGrade()   const
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

//-----------------------methods------------------------
void        Bureaucrat::increment()
{
    std::cout << "incrementing " << _name << "'s grade " << _grade-- << " by 1" << std::endl;
    checkGradeThrowException();
    std::cout << "now " << _name << "'s grade is " << _grade << std::endl;
}

void        Bureaucrat::decrement()
{
    std::cout << "decrementing " << _name << "'s grade " << _grade++ << " by 1" << std::endl;
    checkGradeThrowException();
    std::cout << "now grade is " << _grade << std::endl;
}

void    Bureaucrat::signForm(Form& form)
{
    try {
        if (form.beSigned(*this))
            std::cout << this->_name << " signed '" << form.getName() << "'" << std::endl;
    } catch (std::exception& e) {
        std::cout << this->_name << " couldn't sign form because "
        << this->_grade << " < " << form.getSignGrade() << std::endl;
    }
}

//--------------------helper stuff------------------------
void    Bureaucrat::checkGradeThrowException()    const
{
     if (_grade < 1)
        throw Bureaucrat::GradeTooHighException();
    else if(_grade > 150)
        throw Bureaucrat::GradeTooLowException();
}

//--------------not in class. but to display/work with class properly
std::ostream&   operator<<(std::ostream& os, const Bureaucrat& instance)
{
    return os << instance.getName() << ", bureaucrat grade " << instance.getGrade() << std::endl;
}