/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 14:10:14 by dyarkovs          #+#    #+#             */
/*   Updated: 2025/07/05 23:10:38 by dyarkovs         ###   ########.fr       */
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
PmergeMe<C>::PmergeMe(const PmergeMe<C>& other): _arr(other._arr){}

template <typename C>
PmergeMe<C>&   PmergeMe<C>::operator=(const PmergeMe<C>& other)
{
    if (this != &other)
        _arr = other._arr;
    return *this;
}

template <typename C>
void    PmergeMe<C>::run()
{
    printArr("Before");
    std::clock_t start = std::clock();
    sort();
    std::clock_t end = std::clock();
    printArr("After");
    printTime(start, end);
}

template <typename C>
void    PmergeMe<C>::sort()
{
    swap_pairs();
    insert_sort();
    C   pend;
    C   main;
    main.push_back(*_arr.begin());
    fillArrEachTwoFromIdx(main, 1);
    fillArrEachTwoFromIdx(pend, 2);
    _arr = main;
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
    while (mid >= 0 && static_cast<int>(_arr.size()) != (mid + 1) //edge el
        && el != _arr[mid] && el != _arr[mid + 1] //equal el
        && !(el > _arr[mid] && el < _arr[mid + 1])) //found place
    {
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
    _arr.insert(_arr.begin() + ++mid, el);
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
    int j;
    typename C::iterator b = _arr.begin();
    for (unsigned int i = 3; i < _arr.size(); i += 2)
    {
        for (j = i - 2; j > 0; j -= 2)
        {
            if (_arr[j + 2] < _arr[j])
                std::swap_ranges((b + j - 1), (b + j + 1), (b + j + 1));
            else
                break ;
        }
    }
}
template <typename C>
void    PmergeMe<C>::swap_pairs()
{
     for(unsigned int i = 0; i < _arr.size(); i+= 2)
    {
        if (i + 1 == _arr.size())
            break ;
        if (_arr[i] > _arr[i + 1])
            std::swap(_arr[i], _arr[i + 1]);
    }
}

template <typename C>
std::string PmergeMe<C>::getTypeInfoStr() {
    if (is_same<C, std::vector<int> >::value)
        return "vector<int>";
    else if (is_same<C, std::deque<int> >::value)
        return "deque<int>";
    else
        return "unknown container";
}


template <typename C>
void    PmergeMe<C>::printTime(std::clock_t st, std::clock_t e)
{
    double time = static_cast<double>(e - st) / CLOCKS_PER_SEC * 1000000;
    std::cout << "Time to process a range of " << _arr.size() << " with " << getTypeInfoStr() << " : " << BLUE << time << RE << " microseconds " << std::endl;
}

template <typename C>
void    PmergeMe<C>::printArr(std::string header)
{
    std::cout << B_BLUE << header << ": " << RE;
    for (unsigned int i = 0; i < _arr.size(); i++)
            std::cout << _arr[i] << " ";
    std::cout << std::endl;
}

//Explicit instantiations (at the end, so compiler knows alrady all the fn's here)
template class PmergeMe<std::vector<int> >;
template class PmergeMe<std::deque<int> >;

