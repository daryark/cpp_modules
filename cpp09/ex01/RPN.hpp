/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 23:53:51 by dyarkovs          #+#    #+#             */
/*   Updated: 2025/06/30 13:16:04 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>
#include <stack>
#include <sstream>
#include <string> //getline
#include <cstdlib> //atoi

#include "../colors.hpp"

#define OPS_N 4

class RPN
{
private:
    static std::stack<float> _stack;

    RPN(){};
    ~RPN(){};
    RPN(const RPN&){};
    RPN&    operator=(const RPN&){return *this;};

    static bool     isOp(char);
    static void     doOp(char);
    static float    add(float, float);
    static float    sub(float, float);
    static float    div(float, float);
    static float    mult(float, float);

    struct Operation
    {
        char op;
        float (*fn)(float, float);
    };

    static const Operation operations[OPS_N];

public:
    static float  calc(std::string);
};

