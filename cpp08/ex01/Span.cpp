/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 22:40:25 by dyarkovs          #+#    #+#             */
/*   Updated: 2025/06/27 17:35:10 by dyarkovs         ###   ########.fr       */
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
    std::vector<int> sorted = _vec; //to not modify original
    std::vector<int>::iterator it = sorted.begin(); //no const_iterator to modify the copy in std::sort
    std::vector<int>::iterator end = sorted.end();
    if (it == end || (it + 1) == end)
        throw std::runtime_error("No span can be found");
    std::sort(it, end);
    unsigned int min_span = std::numeric_limits<unsigned int>::max();
    while (++it != end)
        min_span = std::min(min_span, static_cast<unsigned int>(*it - *(it - 1)));
    return  min_span;
}

unsigned int    Span::longestSpan() const
{
    std::vector<int>::const_iterator it = _vec.begin();
    std::vector<int>::const_iterator end = _vec.end();
    if (it == end || (it + 1) == end)
        throw std::runtime_error("No span can be found");
    unsigned int max = 0;
    unsigned int min = std::numeric_limits<unsigned int>::max();
    while (it != end)
    {
        min = std::min(static_cast<unsigned int>(*it), min);
        max = std::max(static_cast<unsigned int>(*it), max);
        it++;
    }
    return (max - min);
}

void    Span::fillContainer(unsigned int n)
{
    if ((_max_size - _vec.size()) < n)
        throw std::runtime_error("Maximum capacity exceeded");
    std::srand(std::time(0));
    for (unsigned int i = 0; i < n; i++)
        _vec.push_back(std::rand());
}