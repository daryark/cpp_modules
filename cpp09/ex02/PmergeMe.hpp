/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 14:10:37 by dyarkovs          #+#    #+#             */
/*   Updated: 2025/07/04 19:11:25 by dyarkovs         ###   ########.fr       */
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

    void    sort();
    void    insert_sort();
    void    fillArrType(C&, bool);

    void    printArr(std::string, unsigned int);
public:
    PmergeMe(int, char**);
    ~PmergeMe(){};
    PmergeMe(const PmergeMe&);
    PmergeMe&   operator=(const PmergeMe&);

    void    run();
};

