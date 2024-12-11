/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 13:59:58 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/12/11 20:01:31 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void)
{
    // try{
    //     Bureaucrat  bur("Bur", 152);
    // } catch (std::exception& e) {
    //     std::cerr << e.what() << std::endl;
    // }
    // std::cout << "-------------------" << std::endl;
    // try{
    //     Bureaucrat  locky("Locky", -152);
    // } catch (std::exception& e) {
    //     std::cerr << e.what() << std::endl;
    // }
    // std::cout << "-------------------" << std::endl;
    // try{
    //     Bureaucrat norm("Norm", 149);
    //     norm.decrement();
    //     norm.decrement(); //after grade is too low(tries 151)
    //     norm.increment(); //will not see this, norm is destructed one line upper
    // } catch (std::exception& e) {
    //     std::cerr << e.what() << std::endl;
    // }
    // std::cout << "-------------------" << std::endl;
    // try{
    //     Bureaucrat frick("Frick", 2);
    //     frick.decrement();
    //     frick.increment();
    //     frick.increment();
    //     frick.increment(); //after grade is too high(tries 0)
    //     frick.decrement(); //will not see this, frick is destructed one line upper
    // } catch (std::exception& e) {
    //     std::cerr << e.what() << std::endl;
    // }
    // std::cout << "-------------------" << std::endl;
    // Bureaucrat printer("Printer", 33);
    // std::cout << printer << std::endl;
    Form f1("First", 10, 10);
    Form f2("Second", 10, 15);
    Form copy(f1);

    std::cout << f1;
    std::cout << f2;
    std::cout << copy;
    std::cout << "copy assignmed \n\n";
    copy = f2;
    std::cout << copy;
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
    Bureaucrat me("Vasileios", 11);
    try
    {
        f1.beSigned(me);
        f2.beSigned(me);
        copy.beSigned(me);
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    Form last("Its working see?", 20, 20);
        try
    {
        last.beSigned(me);
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}

 