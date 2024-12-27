/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 01:38:30 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/12/26 23:35:37 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/Bureaucrat.hpp"

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
    return  "Grade too high, bureaucrat!";
}

const char* Bureaucrat::GradeTooLowException::what()   const throw()
{
    return  "Grade too low, bureaucrat!";
}

//-----------------------methods------------------------
void        Bureaucrat::increment()
{
    std::cout << "incrementing " << _name << "'s grade " << _grade-- << " by 1" << std::endl;
    checkGradeThrowException();
    std::cout << "now " << _name << "'s grade is " << B_GREEN << _grade << RE << std::endl;
}

void        Bureaucrat::decrement()
{
    std::cout << "decrementing " << _name << "'s grade " << _grade++ << " by 1" << std::endl;
    checkGradeThrowException();
    std::cout << "now grade is " << B_YELLOW << _grade << RE << std::endl;
}

void    Bureaucrat::signForm(AForm& form)
{
    try {
        if (form.beSigned(*this))
            std::cout << B_GREEN << _name << " signed '" << form.getName() << "'" << RE << std::endl;
    } catch (std::exception& e) {
        std::cerr << B_RED << _name << " couldn't sign form " << form.getName() << " because "
        << e.what() << RE << std::endl;
    }
}

void    Bureaucrat::execForm(AForm& form)
{
    try {
        form.execute(*this);
        std::cout << B_GREEN << _name << " executed '" << form.getName() << "'" << RE << std::endl;
    }  catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
}

//--------------------helper stuff------------------------
void    Bureaucrat::checkGradeThrowException()
{
     if (_grade < G_HIGHEST)
        throw Bureaucrat::GradeTooHighException();
    else if(_grade > G_LOWEST)
        throw Bureaucrat::GradeTooLowException();
}

//--------------not in class. but to display/work with class properly
std::ostream&   operator<<(std::ostream& os, const Bureaucrat& i)
{
    return os << i.getName() << ", bureaucrat grade " << i.getGrade() << std::endl;
}