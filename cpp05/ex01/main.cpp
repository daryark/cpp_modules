/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 13:59:58 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/12/12 19:26:58 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"


//!check all the tests, especially with bure.signForm() 
//!and with form itself being signed: form.beSigned()
int main(void)
{
    Form f1("First", 10, 10);
    Form f2("Second", 20, 15);
    Form copy(f1);

    std::cout << f1;
    std::cout << f2;
    std::cout << copy;
    std::cout << std::endl;
    try {
        Bureaucrat  importantMan("ImportantMan", 2);
        importantMan.signForm(f2); //signed now
        Bureaucrat  freshman("Freshman", 140);
        freshman.signForm(f2);//already signed
        freshman.signForm(copy);//not signed, low grade
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    copy = f2;
    std::cout << copy;
    std::cout << std::endl;
    //Execeptions
    try
    {
        Form exception("Hello", 10, -10);
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    try
    {
        Form exception("Hello", 10, 151);
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
    Form last("Its working see?", 20, 20);
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

 