/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 00:20:29 by dyarkovs          #+#    #+#             */
/*   Updated: 2025/01/05 04:18:57 by dyarkovs         ###   ########.fr       */
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
