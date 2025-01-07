/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 18:09:51 by dyarkovs          #+#    #+#             */
/*   Updated: 2025/01/07 22:34:44 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <vector>
#include <deque>
#include "easyfind.hpp"
#include "../colors.hpp"

int main(void)
{
    int arr[] = {0, 1, 2, 3};
    //STL containers support constructors that take pointers to an array's beginning and end.
    std::vector<int> vec(arr, arr + 4);
   try {
        std::vector<int>::iterator it = easyfind(vec, 2);
        std::cout << *it << std::endl;
        it = easyfind(vec, 5);
        std::cout << *it << std::endl;
    } catch (std::exception& e)
    {
        std::cerr << RED << e.what() << RE << std::endl;
    }
    std::cout << "---------------------\n";
    std::deque<int> vec2(arr, arr + 4);
    try {
        std::vector<int>::iterator it = easyfind(vec, 2);
        std::cout << *it << std::endl;
        it = easyfind(vec, 5);
        std::cout << *it << std::endl;
    } catch (std::exception& e)
    {
        std::cerr << RED << e.what() << RE << std::endl;
    }
    return 0;
}