/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 21:37:49 by dyarkovs          #+#    #+#             */
/*   Updated: 2025/06/22 22:30:23 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctime>
#include <algorithm>
#include "Span.hpp"

int main(void)
{
    try
    {
        Span span(4);
        span.addNumber(3);
        span.addNumber(1);
        span.addNumber(4);
        span.addNumber(10);
        std::cout << span.longestSpan() << std::endl;
        std::cout << span.shortestSpan() << std::endl;
        span.addNumber(3);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
try
{
    Span span(2);
    span.addNumber(1);
    std::cout << span.longestSpan() << std::endl;
    span.addNumber(2);
}
catch(const std::exception& e)
{
    std::cerr << e.what() << '\n';
}
try
{
    Span span(2);
    span.addNumber(1);
    std::cout << span.shortestSpan() << std::endl;
    span.addNumber(3);
}
catch(const std::exception& e)
{
    std::cerr << e.what() << '\n';
}
    return 0;
}

//*duplicates are possible
// int main()
// {
//     try
//     {
//         Span span(100001);
//         span.fillVec(100000);
//         std::cout << GREEN << "Shortest span: " << span.shortestSpan() << RE << std::endl;
//         std::cout << GREEN << "Longest span: " << span.longestSpan() << RE << std::endl;
//         Span s(100000);
//         s.fillVec(100001);
//         std::cout << RED << "Shortest span: " << s.shortestSpan() << RE << std::endl;
//         std::cout << RED << "Longest span: " << s.longestSpan() << RE << std::endl;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << "Exception: " << e.what() << std::endl;
//     }
//     try
//     {
//         Span span(100002);
//         span.addNumber(4);
//         span.addNumber(44);
//         span.addNumber(3);
//         std::cout << GREEN << "Shortest span: " << span.shortestSpan() << RE << std::endl;
//         std::cout << GREEN << "Longest span: " << span.longestSpan() << RE << std::endl;
//         span.fillVec(100000);
//         std::cout << RED << "Shortest span: " << span.shortestSpan() << RE << std::endl;
//         std::cout << RED << "Longest span: " << span.longestSpan() << RE << std::endl;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << "Exception: " << e.what() << std::endl;
//     }
//     return 0;
// }


//*no duplicates
// int main()
// {
//     const unsigned int size = 100000;
//     Span span(size);

//     std::srand(static_cast<unsigned int>(std::time(0)));

//     // Step 1: Create a vector with 0 to 9999 (unique values)
//     std::vector<unsigned int> numbers;
//     for (unsigned int i = 0; i < size; ++i)
//         numbers.push_back(i);

//     // Step 2: Shuffle the vector for randomness
//     std::random_shuffle(numbers.begin(), numbers.end());

//     // Step 3: Add the numbers to Span
//     for (unsigned int i = 0; i < size; ++i)
//         span.addNumber(numbers[i]);

//     // Step 4: Calculate and print spans
//     try
//     {
//         std::cout << "Shortest span: " << span.shortestSpan() << std::endl;
//         std::cout << "Longest span: " << span.longestSpan() << std::endl;
//     }
//     catch (const std::exception& e)
//     {
//         std::cerr << "Exception: " << e.what() << std::endl;
//     }

//     return 0;
// }