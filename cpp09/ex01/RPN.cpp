/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 00:32:24 by dyarkovs          #+#    #+#             */
/*   Updated: 2025/06/30 14:06:34 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

std::stack<float>   RPN::_stack;

const RPN::Operation    RPN::operations[OPS_N] =
{
    {'+', &RPN::add},
    {'-', &RPN::sub},
    {'/', &RPN::div},
    {'*', &RPN::mult}
};

void   RPN::doOp(char o)
{
    float a;
    float b;
    for(int i = 0; i < OPS_N; i++)
    {
        if (o != operations[i].op)  
            continue ;
        a = _stack.top();
        _stack.pop();
        b = _stack.top();
        _stack.pop();
        _stack.push(operations[i].fn(b, a));
        break ;
    }
}

float   RPN::add(float b, float a){ return (b + a);}

float   RPN::sub(float b, float a){ return (b - a);}

float   RPN::mult(float b, float a){ return (b * a);}

float   RPN::div(float b, float a)
{
    if (a == 0)
        throw std::logic_error("Divistion by zero");
    return (b / a);
}

bool    RPN::isOp(char o)
{
    for(int i = 0; i < OPS_N; i++)
    {
        if (o == operations[i].op)  
            return true;
    }
    return false;
}

float   RPN::calc(std::string s)
{
    _stack = std::stack<float>(); //#1
    std::istringstream iss(s);
    std::string c;
    while(std::getline(iss, c, ' '))
    {
        if (c.empty())
            continue ;
        if ((c.length() == 2 && c[0] == '-' && isdigit(c[1])) || (c.length() == 1 && isdigit(c[0])))
            _stack.push(atoi(c.c_str()));
        else if (c.length() == 1 && isOp(c[0]))
        {
            if (_stack.size() < 2)
                throw std::logic_error("Wrong argument: Not enough operands on stack");;
            doOp(c[0]);
        }
        else
            throw std::runtime_error("Wrong character");
    }
    if (_stack.size() != 1)
        throw std::logic_error("Wrong argument: Not enough operations to calculate");
    // _stack::container_type::clear();
    return _stack.top();
}

//#1  _stack = std::stack<float>();
//clean static=global stack to test multiple times, not run the new prog manually with arg.