/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 13:59:58 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/12/12 15:25:25 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void)
{
    try{
        Bureaucrat  bur("Bur", 152);
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    std::cout << "-------------------" << std::endl;
    try{
        Bureaucrat  locky("Locky", -152);
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    std::cout << "-------------------" << std::endl;
    try{
        Bureaucrat norm("Norm", 149);
        norm.decrement();
        norm.decrement(); //after grade is too low(tries 151)
        norm.increment(); //will not see this, norm is destructed one line upper
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    std::cout << "-------------------" << std::endl;
    try{
        Bureaucrat frick("Frick", 2);
        frick.decrement();
        frick.increment();
        frick.increment();
        frick.increment(); //after grade is too high(tries 0)
        frick.decrement(); //will not see this, frick is destructed one line upper
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    std::cout << "-------------------" << std::endl;
    try {
        Bureaucrat norm("NormNo", 10);
        std::cout << norm;
        Bureaucrat noNorm(norm);
        norm.decrement();
        noNorm = norm;
        std::cout << norm;
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    std::cout << "-------------------" << std::endl;
    try {
        Bureaucrat printer("Printer", 33);
        std::cout << printer << std::endl;
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}

 