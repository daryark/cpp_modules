/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 22:40:09 by dyarkovs          #+#    #+#             */
/*   Updated: 2025/01/07 22:58:49 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <vector>

class Span
{
private:
    std::vector<int> _arr;
public:
    Span(unsigned int n);
    ~Span();

    Span(const Span& other);
    Span&           operator=(const Span& other);
    
    void            addNumber(unsigned int n);
    unsigned int    shortestSpan();
    unsigned int    longestSpan();
};
