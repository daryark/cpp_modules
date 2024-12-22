/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 13:59:58 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/12/22 22:52:32 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

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
    Form f1("First", 10, 10);
    Form f2("Secondddd", 20, 15);
    Form copy(f1);
    Form copy2(f1);


    std::cout << f1;
    std::cout << f2;
    std::cout << copy;
    std::cout << std::endl;
    try {
        Bureaucrat  importantMan("ImportantMan", 2);
        importantMan.signForm(f2); //signed now
        Bureaucrat  freshman("Freshman", 20);
        freshman.signForm(f2);//already signed
        freshman.signForm(copy);//not signed, low grade
        // while (freshman.getGrade() > copy.getSignGrade())
        //     freshman.increment(); //raise grade
        freshman.signForm(copy2);//not signed now //???why it is executed
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    // std::cout << std::endl;
    // copy = f2;
    // std::cout << copy;
    // std::cout << std::endl;
    //Execeptions
    try
    {
        Form exception("Hello", 10, -10);//to high grade
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    try
    {
        Form exception("Hello", 10, 151);//to low grade
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    Bureaucrat me("Dasha", 11);
    try
    {
        me.signForm(f1);
        me.signForm(f2);
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    Form last("?", 20, 20);
        try
    {
        me.signForm(last);
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}

 