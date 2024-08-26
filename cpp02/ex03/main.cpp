/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 17:18:22 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/08/26 23:40:26 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include <sstream>

static Point getInPoint(std::string name)
{
    std::string input;
    std::cout << YELLOW << name << ":  " << RE;
    getline(std::cin, input);
    if (std::cin.eof())
        exit(0);
    size_t pos = input.find(",");
    if (pos != std::string::npos)
        input.erase(pos, 1).insert(pos, " ");
    std::stringstream ss;
    ss << input;
    int x, y;
    if (!(ss >> x >> y))
    {
        std::cerr << "Invalid input, please enter two integers in each point: <int int>."
        << std::endl;
        getInPoint(name);
    }
    return (Point (x, y));
    
}

int main( void ) {
    // bool    res;
    // while (true)
    // {
    //     std::cout << BLUE << "Enter points: A, B, C and P to find. input <int[ ,]int>"
    //     << RE << std::endl;
    //     res = bsp(getInPoint("C"), getInPoint("B"), getInPoint("A"), getInPoint("P"));
    //     std::cout << (res ?  GREEN "YES" : RED "NO") << RE << std::endl;
    // }
    // return 0;
     Point A(0.0f, 0.0f);
    Point B(5.0f, 0.0f);
    Point C(0.0f, 5.0f);

    Point P1(1.0f, 1.0f); // внутри треугольника        true
    Point P2(6.0f, 6.0f); // вне треугольника           false
    Point P3(0.0f, 0.0f); // на вершине треугольника    false
    Point P4(2.5f, 2.5f); // на линии треугольника      false
    Point P5(3.0f, 0.0f); // на ребре AB                false
    Point P6(1.0f, 4.0f); // вне треугольника           false
    Point P7(2.5f, 1.25f); // внутри треугольника       true
    Point P8(5.0f, 5.0f); // вне треугольника           false
    Point P9(-1.0f, -1.0f); // вне треугольника         false
    Point P10(0.0f, 2.5f); // на линии CA               false

    std::cout << "P1 inside triangle ABC: " << (bsp(A, B, C, P1) ? "True" : "False") << std::endl;
    std::cout << "P2 inside triangle ABC: " << (bsp(A, B, C, P2) ? "True" : "False") << std::endl;
    std::cout << "P3 inside triangle ABC: " << (bsp(A, B, C, P3) ? "True" : "False") << std::endl;
    std::cout << "P4 inside triangle ABC: " << (bsp(A, B, C, P4) ? "True" : "False") << std::endl;
    std::cout << "P5 inside triangle ABC: " << (bsp(A, B, C, P5) ? "True" : "False") << std::endl;
    std::cout << "P6 inside triangle ABC: " << (bsp(A, B, C, P6) ? "True" : "False") << std::endl;
    std::cout << "P7 inside triangle ABC: " << (bsp(A, B, C, P7) ? "True" : "False") << std::endl;
    std::cout << "P8 inside triangle ABC: " << (bsp(A, B, C, P8) ? "True" : "False") << std::endl;
    std::cout << "P9 inside triangle ABC: " << (bsp(A, B, C, P9) ? "True" : "False") << std::endl;
    std::cout << "P10 inside triangle ABC: " << (bsp(A, B, C, P10) ? "True" : "False") << std::endl;
}