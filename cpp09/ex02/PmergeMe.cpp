/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 14:10:14 by dyarkovs          #+#    #+#             */
/*   Updated: 2025/07/03 17:41:49 by dyarkovs         ###   ########.fr       */
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
    printArr("Before");
    //start the time;
    sort(1);
    printArr("After");
    //printTime(type of container);
    
}

template <typename C>
void    PmergeMe<C>::sort(unsigned int sz) //*4 (2 * 2 pairs) - example
{
    std::cout << MAGENTA << "pairSz: " << sz << RE << std::endl;
    if (sz * 2 > _arr.size()) //* not enough elems to make 2 arrs to compare
        return ;
    for(unsigned int i = 0; i < _arr.size(); i+= sz * 2)
    {
        if (( _arr.size() > (i + sz*2 - 1)) && (_arr[i + sz - 1] > _arr[i + sz*2 - 1] ))
        {
            std::cout << YELLOW << "swap: " << _arr[i + sz - 1] << ", "
            << _arr[i + sz*2 - 1] << RE << std::endl;
            std::swap_ranges(&_arr[i], &_arr[i + sz], &_arr[i + sz]);
        }
    }
    std::ostringstream oss;
    oss << sz;
    printArr(oss.str());
    sort(sz * 2);
}

template <typename C>
void    PmergeMe<C>::printArr(std::string name)
{
     std::cout << name << ": ";
    for (unsigned int i = 0; i < _arr.size(); i++)
            std::cout << _arr[i] << " ";
    std::cout << std::endl;
}



//Explisit instantiations (at the end, so compiler knows alrady all the fn's here)
template class PmergeMe<std::vector<int> >;
template class PmergeMe<std::deque<int> >;

