/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 18:09:51 by dyarkovs          #+#    #+#             */
/*   Updated: 2025/06/22 15:48:01 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <vector>
#include <deque>
#include "easyfind.hpp"
#include "../colors.hpp"

template <typename T>
static void    printer(typename T::iterator it, const T& container)
{
    if (it == container.end())
        std::cout << "not found" << std::endl;
    else
        std::cout << GREEN << *it << RE << std::endl;
}

int main(void)
{
    int arr[] = {0, 1, 2, 3};
    //STL containers support constructors that take pointers to an array's beginning and end.
    std::vector<int> vec(arr, arr + 4);
    
    printer(easyfind(vec, 2), vec);
    printer(easyfind(vec, 5), vec);
    std::cout << "---------------------\n";
    std::deque<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);

    std::deque<int>::iterator notFound = easyfind(v, 40);  // returns last
    printer(notFound, v);
    printer(easyfind(v, 20), v);
   return 0;
}