/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 14:17:09 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/12/26 23:25:07 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/ShrubberyCreationForm.hpp"

//------------------Constructors & operators-------------------
ShrubberyCreationForm::ShrubberyCreationForm(): AForm("Shrubbery", 145, 137), _target("unknown_target")
{
    std::cout << BI_GREEN << "ShrubberyCreationForm constructor" << RE << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target): AForm("Shrubbery", 145, 137), _target(target)
{
    std::cout << BI_GREEN << "ShrubberyCreationForm constructor with target: " << _target << RE << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    std::cout << BI_RED << "ShrubberyCreationForm destructor" << RE << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other): AForm(other), _target(other._target)
{
    std::cout << "ShrubberyCreationForm copy constructor" << std::endl;   
}

//default copy assignment operator will be called (i mean deafault, not my parent written operator=, but it is called!!!)
//so the need to specify explicitly parent operator= is only when parent has it with some Custom logic.
ShrubberyCreationForm&  ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
    if (this != &other)
        _target = other._target;
    std::cout << "ShrubberyCreationForm copy assignment operator" << std::endl;
    return *this;
}

//--------------------Exceptions------------------------
const char* ShrubberyCreationForm::NotCreatedFileException::what() const throw()//noexcept
{
    return "File isn't created, in Shrubbery!";
}

//-------------------getters----------------------------
const std::string ShrubberyCreationForm::getTarget() const
{
    return _target;
}

//-----------------------methods------------------------
void ShrubberyCreationForm::action() const
{
    std::string filename = _target + "_shrubbery";
    std::fstream outfile(filename.c_str(), std::ios::out);
    if (!outfile.is_open())
        throw NotCreatedFileException();
    outfile << "       🌳\n";
    outfile << "      /   \\\n";
    outfile << "    🌲     🌴\n";
    outfile << "   / \\    / \\\n";
    outfile << " 🌱  🌿  🌵  🍀\n";
    outfile.close();
    std::cout << BI_MAGENTA << "File " << filename << " is created" << std::endl;
}
// std::fstream outfile(filename.c_str(), std::ios::out); OR std::ofstream outfile(filename.c_str());
//if the file doens't exist (when default setup is std::ios::in | std::ios::out) - it crushes, so need to specify different mode
//OR you use (output file stream)ofstream only.