/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 14:01:57 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/12/11 20:02:34 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(): _name("basic_form"), _is_signed(false), _sign_grade(150), _exec_grade(150)
{
    std::cout << GREEN << "Basic form constructor" << RE << std::endl;
}

Form::Form(std::string name, unsigned int sign_grade, unsigned int exec_grade):
_name(name), _is_signed(false), _sign_grade(sign_grade), _exec_grade(exec_grade)
{
    checkGradeThrowException(_exec_grade);
    checkGradeThrowException(_sign_grade);
    std::cout << GREEN << _name << " form constructor" << RE << std::endl;
}

Form::~Form()
{
    std::cout << RED << _name << " form destructor" << RE << std::endl;
}

Form::Form(const Form& other): _name(other._name), _sign_grade(other._sign_grade), _exec_grade(other._exec_grade)
{
    *this = other;
    std::cout << _name << " form copy constructor" << std::endl;
}

Form&   Form::operator=(const Form& other)
{
    if (this != &other)
        _is_signed = other._is_signed;
    std::cout << _name << " form copy constructor" << std::endl;
    return *this;
}

//-------------------getters----------------------------
std::string     Form::getName()   const
{
    return _name;
}

bool            Form::getIsSigned() const
{
    return _is_signed;
}

unsigned int    Form::getSignGrade()    const
{
    return  _sign_grade;
}

unsigned int    Form::getExecGrade()    const
{
    return  _exec_grade;
}

//--------------------Exceptions------------------------
const char*     Form::GradeTooHighException::what()   const throw()
{
    return  "Grade too high!";
}

const char*     Form::GradeTooLowException::what()   const throw()
{
    return  "Grade too low!";
}

//-----------------------methods--------------------------
void            Form::beSigned(const Bureaucrat& person)
{
    unsigned int    grade = person.getGrade();
    if (_is_signed)
    {
        std::cout << this->_name << " form is already signed!" << std::endl;
        return ;
    }
    checkGradeThrowException(grade);
    if (grade <= this->_sign_grade)
        _is_signed = true;
    person.signForm(*this);
    if (grade > this->_sign_grade)
        throw Form::GradeTooLowException();
}

//--------------------helper stuff------------------------
void            Form::checkGradeThrowException(unsigned int grade)    const
{
     if (grade < 1)
        throw Form::GradeTooHighException();
    else if(grade > 150)
        throw Form::GradeTooLowException();
}

//--------------not in class. but to display/work with class properly
std::ostream&   operator<<(std::ostream& os, const Form& i)
{
    return os << YELLOW << i.getName() << ", form sign grade: " << i.getSignGrade() << ", exec grade: "
        << i.getExecGrade() << ", is signed: " << i.getIsSigned() << RE << std::endl;
}