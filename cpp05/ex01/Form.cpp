/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 14:01:57 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/12/22 22:48:50 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

std::string formatStr(std::string s);

Form::Form(): _name("basic_form"), _is_signed(false), _sign_grade(150), _exec_grade(150)
{
    std::cout << GREEN << "Basic form constructor" << RE << std::endl;
}

Form::Form(std::string name, int sign_grade, int exec_grade):
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
    std::cout << _name << " form copy assignment operator" << std::endl;
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

int    Form::getSignGrade()    const
{
    return  _sign_grade;
}

int    Form::getExecGrade()    const
{
    return  _exec_grade;
}

//--------------------Exceptions------------------------
const char*     Form::GradeTooHighException::what()   const throw()
{
    return  "Grade too high, form!";
}

const char*     Form::GradeTooLowException::what()   const throw()
{
    return  "Grade too low, form!";
}

//-----------------------methods--------------------------
bool            Form::beSigned(Bureaucrat& person)
{
    if (_is_signed)
    {
        std::cout << I_BLACK << "'" << _name << "' form is already signed!" << RE << std::endl;
        return false;
    }
    if (person.getGrade() > _sign_grade)
        throw Form::GradeTooLowException();
    _is_signed = true;
    std::cout << "Form '" << _name << "' is successfully signed" << std::endl;
    return true;
}

//--------------------helper stuff------------------------
void            Form::checkGradeThrowException(int grade)    const
{
     if (grade < 1)
        throw Form::GradeTooHighException();
    else if(grade > 150)
        throw Form::GradeTooLowException();
}

//--------------not in class. but to display/work with class properly
std::ostream&   operator<<(std::ostream& os, const Form& i)
{
    std::string form_name = formatStr(i.getName());
    return os << B_WHITE << "Form name: " << form_name
        << "       |sign grade: " << i.getSignGrade()
        << "    |exec grade: " << i.getExecGrade()
        << "    |is signed: " << i.getIsSigned() << RE << std::endl;
}