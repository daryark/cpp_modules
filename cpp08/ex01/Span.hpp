/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 22:40:09 by dyarkovs          #+#    #+#             */
/*   Updated: 2025/06/27 17:30:18 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <vector>
#include <limits>
#include <cstdlib>
#include <ctime>
#include <algorithm>

#include "../colors.hpp"

class Span
{
private:
    std::vector<int>    _vec;
    unsigned int        _max_size;

public:
    Span(unsigned int N);
    ~Span();

    Span(const Span& other);
    Span&           operator=(const Span&);
    
    void            addNumber(unsigned int);
    void            fillContainer(unsigned int);
    unsigned int    shortestSpan()  const;
    unsigned int    longestSpan()   const;

};

//* static memeber fn's don't have access to "this"
//* fn should be static, when it doesn't access and/or modify any member/state of the obj Directly!
//* fn need to be static, when it is used as a fn pointer and is still a member of the class.