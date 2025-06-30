/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 00:51:32 by dyarkovs          #+#    #+#             */
/*   Updated: 2025/06/30 14:04:33 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

static void    Test();

int main(int ac, char** av)
{
    // float res = 0;
    // if (ac != 2)
    // {
        //     std::cerr << "Really? Please use it right!" << std::endl;
        //     return -1;
        // }
        // try {
            //     res = RPN::calc(av[1]);
            //     std::cout << B_BLUE << "result = " << res << RE << std::endl;
            // } catch (const std::exception& e)
            // {
                //     std::cerr << RED << e.what() << RE << std::endl;
                // }
    (void)av;
    (void)ac;
    Test();
    return 0;
}

static void    Test()
{
    const std::string tests[] = {
    // Basic valid cases
    "3 4 +",            // 7
    "5 2 -",            // 3
    "2 3 * ",            // 6
    "8 2 /",            // 4
    "3 -4 *",           // -12
    "-2 5 *",           // -10
    "-3 -4 *",          // 12
    "0 -5 /",           // 0
    "5 -3 -",           // 8
    "-2 -3 *",          // 6
    "4 2 5 * +",        // 14
    "9 -3 /",           // -3
    "0 -0 *",           // 0
    "-5",               // -5
    "0 -5 -",           // 5

    // Error cases
    "1 a +",            // Invalid token
    "2 -a *",           // Invalid token
    "3 ++",             // Invalid token
    "5 +",              // Insufficient operands
    "1 2 3 +",          // Invalid expression structure
    "",                 // Invalid expression structure
    "5 0 /",            // Division by zero
    "3 -0 /",           // Division by zero
    "-5 0 /",           // Division by zero
    "1 2 + -",          // Insufficient operands
    "10",               // Invalid token (multi-digit)
    "-12",              // Invalid token (multi-digit negative)
    "5-",               // Invalid token (malformed token)

    // --- Harder and longer valid cases with float results ---

    // Nested operations, float result
    "8 3 /",            // 2.666...
    "7 2 / 3 +",        // (7/2) + 3 = 3.5 + 3 = 6.5
    "9 2 / 4 *",        // (9/2) * 4 = 4.5 * 4 = 18

    // Multiple operations, some negative, float result
    "2 3 + 4 /",        // (2+3)/4 = 5/4 = 1.25
    "5 1 2 + 4 * + 3 -",// 5 + ((1+2)*4) - 3 = 5 + 12 - 3 = 14

    // Deep stack, float result
    "3 4 + 2 * 7 /",    // ((3+4)*2)/7 = (7*2)/7 = 14/7 = 2

    // Chained operations
    "1 2 + 3 4 + *",    // (1+2)*(3+4) = 3*7 = 21
    "5 9 8 + 4 6 * * 7 + *", // 5 * ((9+8) * (4*6) + 7) = 5 * (17*24 + 7) = 5 * (408 + 7) = 5 * 415 = 2075

    // Complex with negatives and floats
    "-7 2 /",           // -3.5
    "3 -2 /",           // -1.5
    "1 2 + 3 / 4 5 + *",// ((1+2)/3)*(4+5) = (3/3)*9 = 1*9 = 9
    "9 5 - 2 /",        // (9-5)/2 = 4/2 = 2

    // Edge: alternate plus and minus, float
    "1 2 - 3 4 - /",    // (1-2)/(3-4) = (-1)/(-1) = 1

    // Very long valid case, float result
    "1 2 + 3 4 + * 5 6 + 7 8 + * + 9 1 - /", // (((1+2)*(3+4)) + ((5+6)*(7+8))) / (9-1)
                                             // (3*7 + 11*15) / 8 = (21 + 165) / 8 = 186 / 8 = 23.25
};

    for (int i = 0; i < static_cast<int>(sizeof(tests) / sizeof(tests[0])); i++)
    {
        try {
            std::cout << B_BLUE << RPN::calc(tests[i]) << RE << std::endl;}
        catch (const std::exception& e){
                std::cerr << RED << e.what() << RE << std::endl;}
    }
}