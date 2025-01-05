/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 00:20:29 by dyarkovs          #+#    #+#             */
/*   Updated: 2025/01/05 13:52:30 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

// template <typename T, typename U>
template <typename T>
void    iter(T* arr , size_t len, void (*fn)(T&))
{
    for (size_t i = 0; i < len; i++)
        fn(arr[i]);
}

//*overload with CONST
 //!you need to treet CONST separately as it is completely different type
 //! in comparison with anything else. Normal types and complex(structs, classes) are all the same, BUT THE CONST
template <typename T>
void    iter(const T* arr , size_t len, void (*fn)(const T&))
{
    for (size_t i = 0; i < len; i++)
        fn(arr[i]);
}

template <typename T>
void    print(T& t)
{
    std::cout << t << std::endl;
}

template <typename T>
void    increment(T& t)
{
    ++t;
}
