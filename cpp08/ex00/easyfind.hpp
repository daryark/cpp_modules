/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 16:48:29 by dyarkovs          #+#    #+#             */
/*   Updated: 2025/06/22 13:32:06 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <algorithm>
#include <iostream>

template <typename T>
typename T::iterator easyfind(T& container, int n) 
{
   return std::find(container.begin(), container.end(), n);
}



//typename before T::iterator - bcs compiler doesn't know if iterator is already existing TYPE(object type in std lib)
//                              or just a static variable on some custom class like MyClass::iterator (that is some value).



