/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 21:10:30 by dyarkovs          #+#    #+#             */
/*   Updated: 2025/01/04 23:58:27 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <cstdlib> //rand fn
#include <ctime> //srand fn (gives new arg for rand)

class Base
{
public:
    virtual ~Base(){}; //defined for header and made{}
};

class A: public Base {};
class B: public Base {};
class C: public Base {};