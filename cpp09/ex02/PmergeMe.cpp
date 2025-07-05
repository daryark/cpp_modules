/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 14:10:14 by dyarkovs          #+#    #+#             */
/*   Updated: 2025/07/05 21:38:54 by dyarkovs         ###   ########.fr       */
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
    printArr("Before", _arr);
    //start the time;
    sort();
    printArr("After", _arr);
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
    printArr("swaped, 1 stage", _arr);
    std::cout << RE;
    insert_sort();
    C   pend;
    C   main;
    main.push_back(*_arr.begin());
    fillArrEachTwoFromIdx(main, 1);
    fillArrEachTwoFromIdx(pend, 2);
    _arr = main;
    printArr("main", main);
    printArr("pend", pend);
    jakobstahlSequence(pend.size());
    binarySearchInsert(pend);
}

template <typename C>
void    PmergeMe<C>::binaryInsertElem(int el)
{
    int prev_mid = _arr.size();
    int mid = _arr.size() / 2;
    int step;
    int tmp;
    //# cases of exiting the loop = finding the place to insert the element
    //while element is not the first or last in comparison. then compare only with one side
    //while it is not: mid < el < mid+1
    //while it is not equal with one of the elements
    int i = 10;
    while (i--)
    {
        if (!_arr[mid] || _arr.size() == (size_t)(mid+1))//* if arr mid can become negative ?
        {    std::cout << B_RED << "Edge pos" << RE << std::endl;
            break ;
        }
        if (el == _arr[mid] || el == _arr[mid + 1])
        {    std::cout << B_YELLOW << "Equal" << RE << std::endl;
            break ;
        }
        if (el > _arr[mid] && el < _arr[mid + 1])
        {    std::cout << B_GREEN << "Place found" << RE << std::endl;
            break ;
        }
        tmp = mid;
        step = abs(prev_mid - mid) / 2;
        if (step == 0)
            step = 1;
        if (el < _arr[mid])
            mid -= step;
        else
            mid += step;
        prev_mid = tmp;
    }
    std::cout << B_BLUE << "mid: " << _arr[mid] << " el: " << el << " next: " << _arr[mid + 1] << RE << std::endl;
    _arr.insert(_arr.begin() + ++mid, el);
    printArr("inserted: ", _arr);
}

template <typename C>
void    PmergeMe<C>::binarySearchInsert(C& pend)
{
    for (unsigned int i = 0; i < _JIdxs.size(); i++)
    {
        if ((int)pend.size() > _JIdxs[i])
            binaryInsertElem(pend[_JIdxs[i]]);
    }
    
}

template <typename C>
void    PmergeMe<C>::jakobstahlSequence(int size)
{
    std::vector<int>   sequence;
    sequence.push_back(0);
    sequence.push_back(1);
    for (int i = 2; sequence.back() < (size - 1); i++)
        sequence.push_back(sequence[i - 1] + sequence[i - 2] * 2);
    _JIdxs.push_back(0);
    int cur;
    for (unsigned int i = 1; i < sequence.size(); i++)
    {
        cur = sequence[i];
        while (cur > sequence[i - 1])
            _JIdxs.push_back(cur--);
    }
    std::cout << "Jakobstahl idxs: ";
    for (unsigned int i = 0; i < _JIdxs.size(); i++)
            std::cout << YELLOW << _JIdxs[i] << " ";
    std::cout << RE << std::endl;
}

template <typename C>
void    PmergeMe<C>::fillArrEachTwoFromIdx(C& arr, unsigned int start)
{
    for (unsigned int i = start; i < _arr.size(); i += 2)
    {
        arr.push_back(_arr[i]);
        if (_arr.begin() + i + 1 == _arr.end())
            return ;
    }
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
            // std::cout << "j " << j << std::endl;
            if (_arr[j + 2] < _arr[j])
            {
                // std::cout << MAGENTA << "tmp < cur: " << tmp << " < " << _arr[j] << RE << std::endl;
                // // std::cout << MAGENTA << _arr[j] << ", " << _arr[j + 2] << RE << std::endl;
                // std::cout << MAGENTA << "[" << *(b + j -1) << " " << *(b + j) << "]" << " [" << *(b + j + 1) << " " << *(b + j + 2) << "]" << RE << std::endl;
                // _arr[j + 2] = _arr[j];
                std::swap_ranges((b + j - 1), (b + j + 1), (b + j + 1));
            }
            else
            {
                // _arr[j + 2] = tmp;
                break ;
            }
        }
        printArr("- ", _arr);
        // if (tmp >= 0)
        // _arr[j + 2] = tmp;
        // std::swap_ranges()
    }
    // for (unsigned int i = 1; i < _arr.size(); i += 2)
    //     std::cout << YELLOW << _arr[i] << " " << RE;
    std::cout << std::endl;
}

template <typename C>
void    PmergeMe<C>::printArr(std::string header, C& arr)
{
    std::cout << header << ": ";
    for (unsigned int i = 0; i < arr.size(); i++)
            std::cout << arr[i] << " ";
    std::cout << std::endl;
}



//Explisit instantiations (at the end, so compiler knows alrady all the fn's here)
template class PmergeMe<std::vector<int> >;
template class PmergeMe<std::deque<int> >;

