/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 14:10:14 by dyarkovs          #+#    #+#             */
/*   Updated: 2025/07/10 09:58:14 by dyarkovs         ###   ########.fr       */
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
    // create_pairs();

    // for (long unsigned int i = 0; i < _pairs_arr.size(); i++)
    // std::cout << MAGENTA << "[" << _pairs_arr[i].first << ", " << _pairs_arr[i].second << "]" << RE << std::endl;
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

// template <typename C>
// void    PmergeMe<C>::create_pairs()
// {
//     pair p;
//     for (long unsigned int i = 0; i < _arr.size(); i +=2)
//     {
//         if ((i + 1) == _arr.size())
//             p = pair(_arr[i], -1);
//         else
//             p = pair(_arr[i], _arr[i + 1]);
//         _pairs_arr.push_back(p);
//     }
// }

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

// template <typename C>
// void    PmergeMe<C>::sort()
// {
//     // swap_pairs();
//     new_sort(1);
//     // printArr("new sort: ");
//     C   pend;
//     C   main;
//     main.push_back(*_arr.begin());
//     fillArrEachTwoFromIdx(main, 1);
//     fillArrEachTwoFromIdx(pend, 2);
//     _arr = main;
//     // jakobstahlSequence(pend.size());
//     // binarySearchInsert(pend);
// }

template <typename C>
void    PmergeMe<C>::sort(long unsigned int sz) //*4 (2 * 2 pairs) - example
{
    std::cout << MAGENTA << "pairSz: " << sz << RE << std::endl;
    if (sz * 2 > _arr.size()) //* not enough elems to make 2 arrs to compare
        return ;
    for(unsigned int i = 0; i < _arr.size(); i+= sz * 2)
    {
        if (( _arr.size() > (i + sz*2 - 1)) && (_arr[i + sz - 1] > _arr[i + sz*2 - 1] ))
        {
            // std::cout << YELLOW << "swap: " << _arr[i + sz - 1] << ", "
            // << _arr[i + sz*2 - 1] << RE << std::endl;
            std::swap_ranges(&_arr[i], &_arr[i + sz], &_arr[i + sz]);
        }
    }
    std::ostringstream oss;
    oss << sz;
    printArr(oss.str(), _arr);
    sort(sz * 2);
    C pend;
    C main;
    C non_part;
    form_arr_parts(sz, main, pend, non_part);
    C j_idxs;
    jakobstahlSequence(pend.size() / sz, j_idxs);
    printArr("Main arr: ", main);
    printArr("Pend arr: ", pend);
    printArr("Non arr: ", non_part);
    printArr("j_idxs: ", j_idxs);
    // std::cout << B_YELLOW << "j_idxs.size: " << j_idxs.size() << RE << std::endl;
    binarySearchInsert(sz, main, pend, j_idxs);
    std::cout << BG_BLUE << "                  endln                  " << RE << std::endl;
    // main.push_back
}

template <typename C>
void    PmergeMe<C>::form_arr_parts(long unsigned int sz, C& m, C& p, C& non)
{
    long unsigned int i;
    std::cout << GREEN << "sz: " << sz << ", amnt " << _arr.size()/sz << ", left " << _arr.size() % sz << RE << std::endl;
    if (sz * 3 > _arr.size())
        return ;
    m.insert(m.end(), _arr.begin(), _arr.begin() + 2 * sz);
    for (i = sz * 2; i < _arr.size(); i += sz)
    {
        if (_arr.size() >= (i + sz))
            p.insert(p.end(), _arr.begin() + i, _arr.begin() + i + sz);
        else
            break ;
        i+=sz;
        if (_arr.size() >= (i + sz))
            m.insert(m.end(), _arr.begin() + i, _arr.begin() + i + sz);
        else
            break ;
    }
    // std::cout << "it: " << i << std::endl;
    if (_arr.size() > i)
        non.insert(non.end(), _arr.begin() + i, _arr.end());
}

// template <typename C>
// void    PmergeMe<C>::binaryInsertElem(int el)
// {
//     int prev_midI = _arr.size();
//     int mid = _arr.size() / 2;
//     int step;
//     int tmp;
//     while (mid >= 0 && static_cast<int>(_arr.size()) != (mid + 1) //edge el
//         && el != _arr[mid] && el != _arr[mid + 1] //equal el
//         && !(el > _arr[mid] && el < _arr[mid + 1])) //found place
//     {
//         tmp = mid;
//         step = abs(prev_midI - mid) / 2;
//         if (step == 0)
//             step = 1;
//         if (el < _arr[mid])
//             mid -= step;
//         else
//             mid += step;
//         prev_midI = tmp;
//     }
//     _arr.insert(_arr.begin() + ++mid, el);
// }

// template <typename C>
// void    PmergeMe<C>::binarySearchInsert(long unsigned int sz, C& m, C&p, C& j_idxs)
// {
//     for (unsigned int i = 0; i < j_idxs.size(); i++)
//     {
//         if ((int)pend.size() > j_idxs[i])
//             binaryInsertElem(pend[j_idxs[i]]);
//     }
// }

//* new version...
template <typename C> //mid - el - mid + 1 //if mid = 2 mid i is 1 (num of elem is 2)
void    PmergeMe<C>::binaryInsertElem(int el, long unsigned int sz, C& m)
{
    std::cout << B_CYAN << "el: " << el << RE << std::endl;
    int prev_midI = m.size() / sz;
    int midI = prev_midI / 2 + 1;
    int step;
    int tmp;
    std::cout << MAGENTA << "Main full sz: " << prev_midI << " MID: " << midI << RE << std::endl;
    // while (mid >= 0 && static_cast<int>(m.size() / sz) != (mid + 1) //edge el
    //     && el != m[szI(mid, sz)] && el != m[szI(mid, sz) + sz] //equal el
    //     && !(el > m[szI(mid, sz)] && el < m[szI(mid, sz) + sz])) //found place
    while (true)
    {
        if (midI <= 0 || static_cast<int>(m.size() / sz) > midI)
        {
            if (midI < 0)
                std::cout << BG_I_RED << "mid < 0" << RE << std::endl;
            else
                std::cout << BG_I_RED << "mid: " << m[szI(midI - 1, sz)] <<  " el: " << el << " mid+_el: " << m[szI(midI, sz)] << RE << std::endl;
            break ;
        }
        if (el == m[szI(midI - 1, sz)] || el == m[szI(midI, sz)])
        {
            std::cout << BG_I_YELLOW << "EQ mid_el: " << m[szI(midI - 1, sz)] <<  " el: " << el << " mid+_el: " << m[szI(midI, sz)]<< RE << std::endl;
            break ;
        }
        if (el > m[szI(midI - 1, sz)] && el < m[szI(midI, sz)])
        {
            std::cout << BG_I_GREEN << "F mid_el: " << m[szI(midI - 1, sz)] <<  " el: " << el << " mid+_el: " << m[szI(midI, sz)]<< RE << std::endl;
            break ;
        }
        tmp = midI;
        step = abs(prev_midI - midI) / 2;
        if (step == 0)
            step = 1;
        if (el < m[szI(midI - 1, sz)])
        {
            std::cout << BG_I_WHITE << "-step: " << step << ", midI - step: " << midI - step << RE << std::endl;
            midI -= step;
        }
        else
        {
            std::cout << BG_I_CYAN << "+step" << step << ", midI + step: " << midI + step << RE << std::endl;
            midI += step;
        }
        prev_midI = tmp;
    }
    // std::cout << "mid: " << mid << "= " << m[szI(mid, sz)] << ", el: " << el << std::endl;
    std::cout << BG_YELLOW << *(m.begin() + midI*sz) << RE << std::endl;
    // m.insert(m.begin() + midI * sz, el);
}

template <typename C>       //not it, num
unsigned int    PmergeMe<C>::szI(int n, long unsigned int sz)
{
    return (n * sz - 1);
}

template <typename C>
void    PmergeMe<C>::binarySearchInsert(long unsigned int sz, C& m, C&p, C& j_idxs)
{
    (void)m;
    for (unsigned int i = 0; i < j_idxs.size(); i++)
    {
        // std::cout << RED << "pend size: " << static_cast<int>(p.size())
        // << ", p.sz / sz: " << static_cast<int>(p.size() / sz)
        // << ", j_idxs[i]: " << j_idxs[i] << ", i: " << i 
        // << "j_idxs.size(): " << j_idxs.size() << RE << std::endl; 
        if (static_cast<int>(p.size() / sz) > j_idxs[i])
            binaryInsertElem(p[szI((j_idxs[i] + 1), sz)], sz, m);
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
void    PmergeMe<C>::printArr(std::string header, C& arr)
{
    std::cout << B_BLUE << header << ": " << RE;
    for (unsigned int i = 0; i < arr.size(); i++)
            std::cout << arr[i] << " ";
    std::cout << std::endl;
}

//Explicit instantiations (at the end, so compiler knows alrady all the fn's here)
template class PmergeMe<std::vector<int> >;
template class PmergeMe<std::deque<int> >;

