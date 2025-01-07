/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 16:48:29 by dyarkovs          #+#    #+#             */
/*   Updated: 2025/01/07 22:31:02 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <algorithm>
#include <iostream>

template <typename T>
typename T::iterator easyfind(T& t, int toFind) 
{
   typename T::iterator it = std::find(t.begin(), t.end(), toFind);
    if (it != t.end())
        return it;
    throw std::exception();
}

//typename before T::iterator - bcs compiler doesn't know if iterator is already existing TYPE(object type in std lib)
//                              or just a static variable on some custom class like MyClass::iterator (that is some value).