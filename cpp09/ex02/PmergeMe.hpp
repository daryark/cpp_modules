/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 14:10:37 by dyarkovs          #+#    #+#             */
/*   Updated: 2025/07/05 23:06:58 by dyarkovs         ###   ########.fr       */
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

#include "../colors.hpp"

template <typename C>
class PmergeMe
{
private:
    C _arr;
    C _JIdxs;

    void    sort();
    void    swap_pairs();
    void    insert_sort();
    void    fillArrEachTwoFromIdx(C&, unsigned int);
    void    jakobstahlSequence(int);
    void    binarySearchInsert(C&);
    void    binaryInsertElem(int);

    void    printTime(std::clock_t st, std::clock_t end);
    std::string    getTypeInfoStr();
    public:
    PmergeMe(int, char**);
    ~PmergeMe(){};
    PmergeMe(const PmergeMe&);
    PmergeMe&   operator=(const PmergeMe&);
    
    void    run();
    void    printArr(std::string);
};

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