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
    // try
    // {
    //     Span span(2);
    //     span.addNumber(1);
    //     std::cout << span.longestSpan() << std::endl;
    //     std::cout << span.shortestSpan() << std::endl;
    //     span.addNumber(2);
    //     span.addNumber(3);
    // }
    // catch(const std::exception& e)
    // {
    //     std::cerr << e.what() << '\n';
    // }
    return 0;
}