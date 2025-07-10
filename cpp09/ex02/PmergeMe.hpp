/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 14:10:37 by dyarkovs          #+#    #+#             */
/*   Updated: 2025/07/09 17:04:31 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <vector>
#include <deque>
#include <cstdlib>
#include <ctime>
#include <typeinfo>
#include <sstream>
#include <utility> //std::pair
#include <algorithm>

#include "../colors.hpp"

// template <typename C>
// struct C_pair_arr;

// template<>
// struct C_pair_arr<std::vector<int> >
// {
//     typedef std::vector<std::pair<int, int> > type;
// };

// template<>
// struct C_pair_arr<std::deque<int> >
// {
//     typedef std::deque<std::pair<int, int> > type;
// };

template <typename T1, typename T2>
struct is_same
{
    static const bool value = false;
};

template <typename T>
struct is_same <T,T> //specifies the previous struct, and says to EXACTLY match the type
{
    static const bool value = true;
};

template <typename C>
class PmergeMe
{
private:
    typedef std::pair<int, int> pair;

    C _arr;

    void        sort(long unsigned int sz);
    void        form_arr_parts(long unsigned int sz, C& m, C& p, C& non);
    void        jakobstahlSequence(int sz, C& idxs);
    void        binarySearchInsert(long unsigned int, C& m, C& p, C& idxs);
    void        binaryInsertElem(int i, long unsigned int sz, C& m, C& p);

    void        printArr(std::string, C& arr);
    void        printTime(std::clock_t st, std::clock_t end);
    std::string getTypeInfoStr();
    unsigned int    szI(int n, long unsigned int sz);

public:
    PmergeMe(int, char**);
    ~PmergeMe(){};
    PmergeMe(const PmergeMe&);
    PmergeMe&   operator=(const PmergeMe&);
    
    void        run();
    bool        isSorted();
};

//# ln 59, 60
//#typedef std::pair<int, int> pair;
//* typedef - pure stylistic, saying that std::pair<int, int> will be just named "pair" later in the code;
// so i will not need to write tull name with std and <int, int> specialisation inside each time.
// since C++11 uses like that: using pair = std::pair<int, int>;
//# typename C_pair_arr<C>::type _pairs_arr;
//* typename - nwhen accessing a type nested inside a dependent/generic type(on <C>), like C_pair_arr<C>::type.
// the compiler doesn't know if it’s a type or a static variable/function — unless you 
// * explicitly tell it with typename