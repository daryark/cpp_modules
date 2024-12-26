/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 13:59:58 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/12/26 20:22:02 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "incl/Bureaucrat.hpp"
#include "incl/ShrubberyCreationForm.hpp"

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
//!check all the tests, especially with bure.signForm() 
//!and with form itself being signed: form.beSigned()
int main(void)
{
    ShrubberyCreationForm   forest;
    // ShrubberyCreationForm   myForest("my forest");

    forest.action();
    // myForest.action();

    // Form f1("First", 10, 10);
    // Form f2("Secondddd", 20, 15);
    // Form copy(f1);

    // std::cout << f1;
    // std::cout << f2;
    // std::cout << copy;
    // std::cout << std::endl;

    // try {
    //     Bureaucrat  importantMan("ImportantMan", 2);
    //     importantMan.signForm(f2); //signed now
    //     Bureaucrat  freshman("Freshman", 20);
    //     freshman.signForm(f2);//already signed
    //     freshman.signForm(copy);//not signed, low grade
    //     // while (freshman.getGrade() > copy.getSignGrade())
    //     //     freshman.increment(); //raise grade
    //     // freshman.signForm(copy); //signed now
    // } catch (std::exception& e) {
    //     std::cerr << e.what() << std::endl;
    // }
    // std::cout << std::endl;
    // copy = f2;
    // std::cout << copy;
    // std::cout << std::endl;
    // //Execeptions
    // try
    // {
    //     Form exception("Hello", 10, -10);//to high grade
    // }
    // catch (std::exception &e)
    // {
    //     std::cerr << e.what() << std::endl;
    // }
    // try
    // {
    //     Form exception("Hello", 10, 151);//to low grade
    // }
    // catch (std::exception &e)
    // {
    //     std::cerr << e.what() << std::endl;
    // }
    // std::cout << std::endl;
    // 
    // Bureaucrat me("Dasha", 11);
    // try
    // {
    //     me.signForm(f1);
    //     me.signForm(f2);
    //     me.increment();
    //     me.signForm(f1);
    //     while (me.getGrade() > 0)
    //         me.increment();
    //     me.decrement(); //NOT EXEC LINE - while will reach the GradeTooHighException
    // }
    // catch (std::exception &e)
    // {
    //     std::cerr << e.what() << std::endl;
    // }
    return 0;
}

 