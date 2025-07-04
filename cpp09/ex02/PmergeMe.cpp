/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 14:10:14 by dyarkovs          #+#    #+#             */
/*   Updated: 2025/07/04 19:15:56 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

template <typename C>
PmergeMe<C>::PmergeMe(int ac, char** av)
{
    --ac;
    ++av;
    if (ac < 2)
        throw std::runtime_error("Error: not enough arguments");
    for (int i = 0; i < ac; i++)
    {
        for (int c = 0; av[i][c]; c++)
        {
            if (!std::isdigit(av[i][c]))
                throw std::runtime_error("Error: only positive digits accepted");
        }
        _arr.push_back(atoi(av[i]));
    }
}

template <typename C>
PmergeMe<C>&   PmergeMe<C>::operator=(const PmergeMe<C>& other)
{
    // if (this != &other)
    //     _arr = other._arr;
    (void)other;
    return *this;
}

template <typename C>
void    PmergeMe<C>::run()
{
    printArr("Before", 1);
    //start the time;
    sort();
    printArr("After", 1);
    //printTime(type of container);
    
}

template <typename C>
void    PmergeMe<C>::sort()
{
    for(unsigned int i = 0; i < _arr.size(); i+= 2)
    {
        if (i + 1 == _arr.size())
            break ;
        if (_arr[i] > _arr[i + 1])
            std::swap(_arr[i], _arr[i + 1]);
    }
    std::cout << YELLOW;
    printArr("swaped, 1 stage", 1);
    std::cout << RE;
    insert_sort();
    //#add 1 lowest element to the main also!!!
    // C   pend.reserve(_arr.size() / 2);
    // C   main.reserve(_arr.size() / 2);
    // fillArrType(main, 1);
    // fillArr(pend, 0);
    // if (_arr.size() % 2)
    //     pend.push_back(_arr[_arr.back()]);
    // _arr = main;
}

template <typename C>
void    PmergeMe<C>::fillArrType(C& arr, bool at)
{
    for (unsigned int i = at; i < _arr.size(); i += 2)
        arr.push_back(_arr[i]);
}

template <typename C>
void    PmergeMe<C>::insert_sort()
{
    // int sz = 2;
    typename C::iterator b = _arr.begin();
    for (unsigned int i = 3; i < _arr.size(); i += 2)
    {
        std::cout << GREEN << *(b + i) << RE;
        std::cout << " i:" << i << " pos(" << i + 1 << ")" << std::endl;
        // int tmp = _arr[i];//# i don't need tmp ? if i swap nearest pairs and preserve all the nums ?
        //# or i need tmp just to orient on the value
        int j;
        for (j = i - 2; j > 0; j -= 2)
        {
            std::cout << "j " << j << std::endl;
            if (_arr[j + 2] < _arr[j])
            {
                // std::cout << MAGENTA << "tmp < cur: " << tmp << " < " << _arr[j] << RE << std::endl;
                // // std::cout << MAGENTA << _arr[j] << ", " << _arr[j + 2] << RE << std::endl;
                // std::cout << MAGENTA << "[" << *(b + j -1) << " " << *(b + j) << "]" << " [" << *(b + j + 1) << " " << *(b + j + 2) << "]" << RE << std::endl;
                // _arr[j + 2] = _arr[j];
                std::swap_ranges((b + j - 1), (b + j + 1), (b + j + 1));
                printArr("- ", 1);
            }
            else
            {
                // _arr[j + 2] = tmp;
                break ;
            }
        }
        // if (tmp >= 0)
        // _arr[j + 2] = tmp;
        // std::swap_ranges()
    }
    // for (unsigned int i = 1; i < _arr.size(); i += 2)
    //     std::cout << YELLOW << _arr[i] << " " << RE;
    std::cout << std::endl;
}

template <typename C>
void    PmergeMe<C>::printArr(std::string name, unsigned int it)
{
    std::cout << name << ": ";
    for (unsigned int i = 0; i < _arr.size(); i+= it)
            std::cout << _arr[i] << " ";
    std::cout << std::endl;
}



//Explisit instantiations (at the end, so compiler knows alrady all the fn's here)
template class PmergeMe<std::vector<int> >;
template class PmergeMe<std::deque<int> >;

