/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 14:01:57 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/12/26 22:04:06 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/AForm.hpp"

std::string formatStr(std::string s);

AForm::AForm(): _name("basic_form"), _is_signed(false), _sign_grade(150), _exec_grade(150)
{
    std::cout << GREEN << "Basic form constructor" << RE << std::endl;
}

//----------------------Constructors & operators----------------------
AForm::AForm(std::string name, int sign_grade, int exec_grade):
_name(name), _is_signed(false), _sign_grade(sign_grade), _exec_grade(exec_grade)
{
    checkGradeThrowException(_sign_grade);
    checkGradeThrowException(_exec_grade);
    std::cout << GREEN << _name << " form constructor" << RE << std::endl;
}

AForm::~AForm()
{
    std::cout << RED << _name << " form destructor" << RE << std::endl;
}

AForm::AForm(const AForm& other)
    : _name(other._name), _is_signed(other._is_signed), _sign_grade(other._sign_grade), _exec_grade(other._exec_grade)
{
    std::cout << _name << " form copy constructor" << std::endl;
}

AForm&   AForm::operator=(const AForm& other)
{
    if (this != &other)
        _is_signed = other._is_signed;
    std::cout << _name << " form copy assignment operator" << std::endl;
    return *this;
}

//--------------------Exceptions------------------------
const char*     AForm::GradeTooHighException::what()   const throw()
{
    return  "Grade too high, form!";
}

const char*     AForm::GradeTooLowException::what()   const throw()
{
    return  "Grade too low, form!";
}

const char*     AForm::NotSignedException::what()   const throw()
{
    return  "Not signed, form!";
}

//-------------------getters----------------------------
std::string     AForm::getName()   const
{
    return _name;
}

bool            AForm::getIsSigned() const
{
    return _is_signed;
}

int    AForm::getSignGrade()    const
{
    return  _sign_grade;
}

int    AForm::getExecGrade()    const
{
    return  _exec_grade;
}

//-----------------------methods--------------------------
bool            AForm::beSigned(Bureaucrat& person)
{
    if (_is_signed)
    {
        std::cout << I_BLACK << "'" << _name << "' form is already signed!" << RE << std::endl;
        return false;
    }
    if (person.getGrade() > _sign_grade)
        throw AForm::GradeTooLowException();
    _is_signed = true;
    std::cout << "AForm '" << _name << "' is successfully signed" << std::endl;
    return true;
}

void            AForm::execute(const Bureaucrat& executor)  const
{
    std::cout << "is signed: " << _is_signed << ", grade bureaucrat: " << executor.getGrade() << ", form sign grade: " << _sign_grade
        << ", exec grade: " << _exec_grade << std::endl;
    if (!_is_signed)
        throw NotSignedException();
    else if (_exec_grade < executor.getGrade())
        throw GradeTooLowException();
    else
        action();
}

//--------------------helper stuff------------------------
void            AForm::checkGradeThrowException(int grade)
{
     if (grade < G_HIGHEST)
        throw AForm::GradeTooHighException();
    else if(grade > G_LOWEST)
        throw AForm::GradeTooLowException();
}

//--------------not in class. but to display/work with class properly
std::ostream&   operator<<(std::ostream& os, const AForm& i)
{
    std::string form_name = formatStr(i.getName());
    return os << B_WHITE << "AForm name: " << form_name
        << "       |sign grade: " << i.getSignGrade()
        << "    |exec grade: " << i.getExecGrade()
        << "    |is signed: " << i.getIsSigned() << RE << std::endl;
}