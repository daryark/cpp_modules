/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 23:45:07 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/12/27 03:23:19 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/Intern.hpp"

//------------------Constructors & operators-------------------
Intern::Intern()
{
    std::cout << BI_WHITE << "Intern constructor" << RE << std::endl;
}

Intern::~Intern()
{
    std::cout << BI_WHITE << "Intern destructor" << RE << std::endl;
}

//--------------------Exceptions------------------------
const char* Intern::FormNameNotFoundException::what()    const throw() //noexcept
{
    return "Form name is invalid, Intern!";
}

//-----------------------methods------------------------

AForm*  Intern::makeShrubberyForm(std::string target)
{
    return new ShrubberyCreationForm(target);
}

AForm*  Intern::makeRobotomyForm(std::string target)
{
    return new RobotomyRequestForm(target);
}

AForm*  Intern::makePresidentalForm(std::string target)
{
    return new PresidentialPardonForm(target);
}

AForm*  Intern::makeForm(std::string form_name, std::string target)
{
    const std::string formNames[3] = {"shrubbery creation", "robotomy request", "presidental pardon"};
    AForm*  (Intern::*makeFormFns[3])(std::string target) = 
        {&Intern::makeShrubberyForm, &Intern::makeRobotomyForm, &Intern::makePresidentalForm};
    for (int i = 0; i < 3; i++)
    {
        if (form_name == formNames[i])
            return (this->*makeFormFns[i])(target);
    }
    throw FormNameNotFoundException();
}
//*AForm*  (Intern::*makeFormFns[3])(std::string target)
//* (type of fn that will be inside)(args type)
//*  Intern::* - pointers on fns inside Intern class, makeFormFns[3] - name and amnt of pointers to fns

//*this->* - tells that we call fn* inside Intern class, not just method(fn)
//*(first the fn need to be defeferenced)(after is called with this argument) - ()();
















//needs to use header <algorithm> and c++11 :(
// AForm*  Intern::makeForm(std::string form_name, std::string form_target)
// {
//     std::map<std::string, std::function<AForm*(const std::string&)>> form_creation = {
//         {"robotomy request", [](const std::string& target){return new RobotomyRequestForm(target);}},
//         {"presidental pardon", [](const std::string& target){return new PresidentialPardonForm(target)};},
//         {"shrubbery creation", [](const std::string& target){return new ShrubberyCreationForm(target)}}};
//     auto it = form_creation.find(std::tolower(form_name));
//     if (it = form_creation.end())
//         throw FormNameNotFoundException();
//     return it->second(form_target);
// }
//std::map < str, fn<AForm*(return type) (const std::string& - arg)> >; map is arr with {key, value}.
// auto - type of iterator present on the map obj.
//form_creation.find(form_name)  if value found - returns iterator on pair{key(first), value(second)}; else - it pointing on the end of map obj memory
// to run the lambda/noname fn from value in the obj - dereference it.