/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 14:19:14 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/12/26 23:15:00 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/PresidentialPardonForm.hpp"

//------------------Constructors & operators-------------------
PresidentialPardonForm::PresidentialPardonForm(): AForm("Presidental", 25, 5), _target("unknown_target")
{
    std::cout << BI_GREEN << "PresidentialPardonForm constructor" << RE << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target): AForm("Presidental", 25, 5), _target(target)
{
    std::cout << BI_GREEN << "PresidentialPardonForm constructor with target: " << _target << RE << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
    std::cout << BI_RED << "PresidentialPardonForm destructor" << RE << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other): AForm(other), _target(other._target)
{
    std::cout << "PresidentialPardonForm copy constructor" << std::endl;   
}

//default copy assignment operator will be called (i mean deafault, not my parent written operator=, but it is called!!!)
//so the need to specify explicitly parent operator= is only when parent has it with some Custom logic.
PresidentialPardonForm&  PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
    if (this != &other)
        _target = other._target;
    std::cout << "PresidentialPardonForm copy assignment operator" << std::endl;
    return *this;
}

//-------------------getters----------------------------
const std::string PresidentialPardonForm::getTarget() const
{
    return _target;
}

//-----------------------methods------------------------
void PresidentialPardonForm::action() const
{
    std::cout << BI_YELLOW << _target << " has been pardoned by Zaphod Beeblebrox." << RE << std::endl;
}