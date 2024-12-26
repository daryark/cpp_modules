/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 14:17:45 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/12/26 22:57:27 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/RobotomyRequestForm.hpp"

//------------------Constructors & operators-------------------
RobotomyRequestForm::RobotomyRequestForm(): AForm("Robotomy", 145, 137), _target("unknown_target")
{
    std::cout << BI_GREEN << "RobotomyRequestForm constructor" << RE << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target): AForm("Robotomy", 145, 137), _target(target)
{
    std::cout << BI_GREEN << "RobotomyRequestForm constructor with target: " << _target << RE << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
    std::cout << BI_RED << "RobotomyRequestForm destructor" << RE << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other): AForm(other), _target(other._target)
{
    std::cout << "RobotomyRequestForm copy constructor" << std::endl;   
}

//default copy assignment operator will be called (i mean deafault, not my parent written operator=, but it is called!!!)
//so the need to specify explicitly parent operator= is only when parent has it with some Custom logic.
RobotomyRequestForm&  RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
    if (this != &other)
        _target = other._target;
    std::cout << "RobotomyRequestForm copy assignment operator" << std::endl;
    return *this;
}
//-----------------------methods------------------------
void RobotomyRequestForm::action() const
{
    srand(time(NULL));
    int n = rand() % 2;
    if (n)
        std::cout << BI_YELLOW << "🤖 " << _target << " has been robotomized" << RE << std::endl;
    else
        std::cout << BI_BLACK << "Robotomy failed for " << _target << RE << std::endl;
}
// std::fstream outfile(filename.c_str(), std::ios::out); OR std::ofstream outfile(filename.c_str());
//if the file doens't exist (when default setup is std::ios::in | std::ios::out) - it crushes, so need to specify different mode
//OR you use (output file stream)ofstream only.