/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 14:10:37 by dyarkovs          #+#    #+#             */
/*   Updated: 2025/07/05 16:55:08 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <vector>
#include <deque>
#include <cstdlib>
#include <sstream> //

#include "../colors.hpp"

template <typename C>
class PmergeMe
{
private:
    C _arr;
    C _JIdxs;

    void    sort();
    void    insert_sort();
    void    fillArrEachTwoFromIdx(C&, unsigned int);
    void    jakobstahlSequence(int);
    void    binarySearchInsert(C&);
    void    binaryInsertElem(int);

    void    printArr(std::string,  C&);
public:
    PmergeMe(int, char**);
    ~PmergeMe(){};
    PmergeMe(const PmergeMe&);
    PmergeMe&   operator=(const PmergeMe&);

    void    run();
};

