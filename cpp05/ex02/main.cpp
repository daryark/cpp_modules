/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 13:59:58 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/12/26 23:35:48 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "incl/Bureaucrat.hpp"
#include "incl/ShrubberyCreationForm.hpp"
#include "incl/RobotomyRequestForm.hpp"
#include "incl/PresidentialPardonForm.hpp"

std::string formatStr(std::string s)
{
    if (s.length() > 8)
        return(s.substr(0, 8 - 1).append("."));
    else
    {
        std::string spaces(8 - s.length(), ' ');
        return (s + spaces);
    }
}

//*Write good tests for each class try/catch, good/bad grades test
int main(void)
{
    // ShrubberyCreationForm
    {
        ShrubberyCreationForm ShrubbForm("Schrubb Form");
        Bureaucrat BureaucratCanSign("I can sign", 130);
        Bureaucrat BureaucratCantSign("I cant sign", 146);
        try
        {
            ShrubbForm.beSigned(BureaucratCantSign); // Exception occurs
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        try
        {
            BureaucratCanSign.execForm(ShrubbForm); // Exception occurs
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        try
        {
            ShrubbForm.beSigned(BureaucratCanSign); // No Exception
            BureaucratCanSign.execForm(ShrubbForm);
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
    }

    // Presidential
    std::cout << std::endl;

    {
        PresidentialPardonForm PresidentForm("President Form");
        Bureaucrat BureaucratCanSign("I can sign", 4);
        Bureaucrat BureaucratCantSign("I cant sign", 26);
        try
        {
            PresidentForm.beSigned(BureaucratCantSign); // Exception occurs
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        try
        {
            BureaucratCanSign.execForm(PresidentForm); // Exception occurs
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        try
        {
            PresidentForm.beSigned(BureaucratCanSign); // No Exception
            BureaucratCanSign.execForm(PresidentForm);
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
    }

    // Robotomy
    std::cout << std::endl;

    {
        RobotomyRequestForm RobotForm("Robotomy Form");
        Bureaucrat BureaucratCanSign("I can sign", 44);
        Bureaucrat BureaucratCantSign("I cant sign", 73);
        try
        {
            RobotForm.beSigned(BureaucratCantSign); // Exception occurs
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        try
        {
            BureaucratCanSign.execForm(RobotForm); // Exception occurs
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        try
        {
            RobotForm.beSigned(BureaucratCanSign); // No Exception
            BureaucratCanSign.execForm(RobotForm);

        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
    }
}
 