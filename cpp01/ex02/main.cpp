/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 22:51:15 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/08/18 23:08:05 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(void)
{
    std::string s = "HI THIS IS BRAIN";
    std::string *stringPTR = &s;
    std::string &stringREF = s;
    std::cout << "Memory addresses:" << std::endl;
    std::cout << "PTR (stringPTR):  " << stringPTR << std::endl;
    std::cout << "REF (&stringREF):  " << &stringREF << std::endl;
    std::cout << "Values:" << std::endl;
    std::cout << "PTR (*stringPTR):  " << *stringPTR << std::endl;
    std::cout << "REF (stringREF):  " << stringREF << std::endl;
    return (0);
}
