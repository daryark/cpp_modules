/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 14:10:14 by dyarkovs          #+#    #+#             */
/*   Updated: 2025/07/11 12:45:26 by dyarkovs         ###   ########.fr       */
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
    printArr("Before", _arr);
    std::clock_t start = std::clock();
    sort(1);
    std::clock_t end = std::clock();
    printArr("After", _arr);
    printTime(start, end);
}

template <typename C>
void    PmergeMe<C>::sort(long unsigned int sz)
{
    if (sz * 2 > _arr.size())
        return ;
    for(unsigned int i = 0; i < _arr.size(); i+= sz * 2)
    {
        if (( _arr.size() > (i + 2 * sz - 1))
        && (*(_arr.begin() + i + sz - 1) > *(_arr.begin() + i + 2 * sz - 1) ))
            std::swap_ranges(_arr.begin() + i, _arr.begin() + i + sz, _arr.begin() + i + sz);
    }
    sort(sz * 2);
    C pend;
    C main;
    C non_part;
    C j_idxs;
    form_arr_parts(sz, main, pend, non_part);
    jakobstahlSequence(pend.size() / sz, j_idxs);
    binarySearchInsert(sz, main, pend, j_idxs);
    _arr = main;
    if(non_part.size() > 0)
    {
        if (sz > 1)
        _arr.insert(_arr.end(), non_part.begin(), non_part.end());
        else
            binaryInsertElem(0, 1, _arr, non_part);
    }
}

template <typename C>
void    PmergeMe<C>::form_arr_parts(long unsigned int sz, C& m, C& p, C& non)
{
    long unsigned int i;
    bool isMain = false;
    m.insert(m.end(), _arr.begin(), _arr.begin() + 2 * sz);
    for (i = sz * 2; i < _arr.size(); i += sz)
    {
        if (_arr.size() < (i + sz))
            break ;
        isMain ? insertBack(m, m.size(), _arr, i, sz) : insertBack(p, p.size(), _arr, i, sz);
        isMain = !isMain;
    }
    if (_arr.size() > i)
        non.insert(non.end(), _arr.begin() + i, _arr.end());
}

template <typename C>
unsigned int    PmergeMe<C>::szI(int i, long unsigned int sz)
{
    return (i * sz - 1);
}

template <typename C>
void    PmergeMe<C>::insertBack(C& a, int posA, C& b, long unsigned int posB, long unsigned int sz)
{
    a.insert(a.begin() + posA, b.begin() + posB, b.begin() + posB + sz);
}

template <typename C>
void    PmergeMe<C>::binaryInsertElem(int i, long unsigned int sz, C& m, C& p) 
{
    int el = p[szI(i + 1, sz)];
    long unsigned int prev_midI = m.size() / sz;
    long unsigned int midI = prev_midI / 2;
    long unsigned int step;
    long unsigned int tmp;
    while (midI > 0 && m.size() / sz != midI //edge el
        && el != m[szI(midI, sz)] && el != m[szI(midI + 1, sz)] //equal el
        && !(el > m[szI(midI, sz)] && el < m[szI(midI + 1, sz)])) //found place
    {
        tmp = midI;
        step = abs(prev_midI - midI) / 2;
        if (step == 0)
            step = 1;
        if (el < m[szI(midI, sz)])
            midI -= step;
        else
            midI += step;
     
        prev_midI = tmp;
    }
    insertBack(m, midI * sz, p, i * sz, sz);
}
//midI position of the middle chunk(biggest=last=target elem), and also its it
//ex: midI = 1; it will work for 0 iteration midI * sz -1 = 1 * 8 - 1 = 7 el in the first(0 it) chunk

template <typename C>
void    PmergeMe<C>::binarySearchInsert(long unsigned int sz, C& m, C&p, C& j_idxs)
{
    for (unsigned int i = 0; i < j_idxs.size(); i++)
    {
        if (static_cast<int>(p.size() / sz) > j_idxs[i])
            binaryInsertElem(j_idxs[i], sz, m, p);
    }
}

template <typename C>
void    PmergeMe<C>::jakobstahlSequence(int size, C& j_idxs)
{
    C  sequence;
    sequence.push_back(0);
    sequence.push_back(1);
    for (int i = 2; sequence.back() < (size - 1); i++)
        sequence.push_back(sequence[i - 1] + sequence[i - 2] * 2);
    j_idxs.push_back(0);
    int cur;
    for (unsigned int i = 1; i < sequence.size(); i++)
    {
        cur = sequence[i];
        while (cur > sequence[i - 1])
            j_idxs.push_back(cur--);
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
    std::cout << "Time to process a range of " << _arr.size() << " with " << getTypeInfoStr() << " : " << B_GREEN << time << RE << " microseconds " << std::endl;
}

template <typename C>
void    PmergeMe<C>::printArr(std::string header, C& arr)
{
    std::cout << B_BLUE << header << ": " << RE;
    for (unsigned int i = 0; i < arr.size(); i++)
            std::cout << arr[i] << " ";
    std::cout << std::endl;
}

template <typename C>
bool PmergeMe<C>::isSorted() {
    return std::adjacent_find(_arr.begin(), _arr.end(), std::greater<typename C::value_type>()) == _arr.end();
}

//Explicit instantiations (at the end, so compiler knows alrady all the fn's here)
template class PmergeMe<std::vector<int> >;
template class PmergeMe<std::deque<int> >;

