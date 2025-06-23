/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 22:40:25 by dyarkovs          #+#    #+#             */
/*   Updated: 2025/06/23 12:59:29 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(unsigned int N): _max_size(N) {};

Span::~Span() {};

Span::Span(const Span& other):_vec(other._vec), _max_size(other._max_size){}

Span&   Span::operator=(const Span& other)
{
    if (this != &other)
    {
        _vec = other._vec;
        _max_size = other._max_size;
    }
    return *this;
}

void    Span::addNumber(unsigned int n)
{
    if (_max_size > _vec.size())
        _vec.push_back(n);
    else
        throw std::runtime_error("Container is filled, no space left");
}

unsigned int    Span::shortestSpan()    const
{
    return  calcSpan(min, std::numeric_limits<unsigned int>::max());
}

unsigned int    Span::longestSpan() const
{
    return  calcSpan(max, 0);
}

unsigned int    Span::calcSpan(bool (*compare)(unsigned int& curr, unsigned int& diff), unsigned int edge_limit)    const
{
    unsigned int diff = edge_limit;
    
    std::vector<int>::const_iterator it = _vec.begin();
    std::vector<int>::const_iterator end = _vec.end();
    if (it == end || (it + 1) == end)
    throw std::runtime_error("No span can be found");
    for (unsigned int i = 0; i < _vec.size(); i++)
    {
        std::vector<int>::const_iterator curr_it = it;
        while(++curr_it != end)
        {
            unsigned int curr = std::abs(*it - *curr_it);
            if (compare(curr, diff))
            diff = curr;
        }
        it++;
    }
    return  diff;
}

bool    Span::min(unsigned int& a, unsigned int& b)
{
    return a < b;
}

bool    Span::max(unsigned int& a, unsigned int& b)
{
    return a > b;
}

void    Span::fillContainer(unsigned int n)
{
    if ((_max_size - _vec.size()) < n)
        throw std::runtime_error("Maximum capacity exceeded");
    std::srand(std::time(0));
    for (unsigned int i = 0; i < n; i++)
        _vec.push_back(std::rand());
}