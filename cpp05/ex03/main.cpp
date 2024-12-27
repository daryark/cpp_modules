/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 13:59:58 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/12/27 03:30:56 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sstream>

#include "incl/Bureaucrat.hpp"
#include "incl/ShrubberyCreationForm.hpp"
#include "incl/RobotomyRequestForm.hpp"
#include "incl/PresidentialPardonForm.hpp"
#include "incl/Intern.hpp"

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
   std::cout << "\nCase 1: Signing a form with insufficient grade\n" << std::endl;
    AForm* form1 = NULL;
    try {
        Intern intern;
        form1 = intern.makeForm("shrubbery creation", "Garden");
        Bureaucrat alice("Alice", 150);
        form1->beSigned(alice);
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    delete form1;

    std::cout << "\nCase 2: Successfully signing and executing a form\n" << std::endl;
    AForm* form2 = NULL;
    try {
        Intern intern;
        form2 = intern.makeForm("presidental pardon", "Criminal");
        Bureaucrat bob("Bob", 1);
        form2->beSigned(bob);
        bob.execForm(*form2);
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    delete form2;

    std::cout << "\nCase 3: Attempting to create an invalid form\n" << std::endl;
    AForm* form3 = NULL;
    try {
        Intern intern;
        form3 = intern.makeForm("invalid form", "Target");
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    delete form3;

    std::cout << "\nCase 4: Creating and executing RobotomyRequestForm\n" << std::endl;
    AForm* form4 = NULL;
    try {
        Intern intern;
        form4 = intern.makeForm("robotomy request", "Bender");
        Bureaucrat charlie("Charlie", 1);
        form4->beSigned(charlie);
        charlie.execForm(*form4);
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    delete form4;

    std::cout << "\nCase 5: Attempting to execute an unsigned form\n" << std::endl;
    AForm* form5 = NULL;
    try {
        Intern intern;
        form5 = intern.makeForm("shrubbery creation", "Park");
        Bureaucrat dave("Dave", 1);
        dave.execForm(*form5);
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    delete form5;

    std::cout << "\nCase 6: Using a low-grade bureaucrat to execute a form\n" << std::endl;
    AForm* form6 = NULL;
    try {
        Intern intern;
        form6 = intern.makeForm("presidental pardon", "Criminal");
        Bureaucrat frank("Frank", 150);
        form6->beSigned(frank);
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    delete form6;

    std::cout << "\nCase 7: Multiple forms created by the same intern\n" << std::endl;
    AForm* form7 = NULL;
    AForm* form8 = NULL;
    AForm* form9 = NULL;
    try {
        Intern intern;
        form7 = intern.makeForm("shrubbery creation", "Garden");
        form8 = intern.makeForm("presidental pardon", "Politician");
        form9 = intern.makeForm("robotomy request", "Robot");
        Bureaucrat grace("Grace", 1);
        form7->beSigned(grace);
        form8->beSigned(grace);
        form9->beSigned(grace);
        grace.execForm(*form7);
        grace.execForm(*form8);
        grace.execForm(*form9);
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    delete form7;
    delete form8;
    delete form9;

    // std::cout << "\nCase 8: Dynamic form creation and deletion in a loop\n" << std::endl;
    // try {
    //     Intern intern;
    //     for (int i = 0; i < 5; ++i) {
    //         std::ostringstream ossForm;
    //         ossForm << "Garden_" << (i + 1);
    //         AForm* form10 = intern.makeForm("shrubbery creation", ossForm.str());
    //         Bureaucrat signer("Signer", 1);
    //         form10->beSigned(signer);
    //         signer.execForm(*form10);
    //         delete form10;
    //     }
    // } catch (const std::exception& e) {
    //     std::cerr << "Error: " << e.what() << std::endl;
    // }

    return 0;
}
 