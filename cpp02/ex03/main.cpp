/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 17:18:22 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/08/29 21:20:46 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include <sstream>
#include <cstdlib>
#include <cstdio>

static std::string  getlineSafe()
{
    std::string input;
    getline(std::cin, input);
    if (std::cin.eof())
        exit(0);
    return (input);
}

static void cleanConsole()
{
    if (!std::system("cls"))
        return ;
    std::cout << "\033[2J\033[1;1H";
}

static Point getInPoint(std::string name)
{
    std::string input;
    std::cout << YELLOW << name << ":  " << RE;
    input = getlineSafe();
    size_t pos = input.find(",");
    if (pos != std::string::npos)
        input.erase(pos, 1).insert(pos, " ");
    std::stringstream ss;
    ss << input;
    float x, y;
    if (!(ss >> x >> y) || ss.peek() != EOF )
    {
        std::cerr << RED << "Invalid input, please enter two integers in each point: <num[ ,]num>, num - int/float."
         << RE << std::endl;
        getInPoint(name);
    }
    return (Point (x, y));
    
}
static void showRes(bool res)
{
    std::cout << (res ?  GREEN "YES" : RED "NO") << RE << std::endl;
}

static void showInData(const Point &A, const Point&B, const Point& C, const Point& P)
{
    std::cout << " A(" << A.getX() << ", " << A.getY() << "), B(" << B.getX() << ", " << B.getY() << "), C(" << C.getX() << ", " << C.getY() << ").   P(" << P.getX() << ", " << P.getY() << ")   " << std::endl;
}

static void manualMode()
{
    std::string in;
    while (true)
    {
        cleanConsole();
        std::cout << BLUE << "Enter points: A, B, C and P to find. input <num[ ,]num>, num - int/float"
        << RE << std::endl;
        showRes(bsp(getInPoint("C"), getInPoint("B"), getInPoint("A"), getInPoint("P")));
        in = getlineSafe();
        if (in == "q")
            exit(0);
        else if (in != "")
            return ;
    }
}

static void testMode()
{
    cleanConsole();
    Point A(0.0f, 0.0f);
    Point B(5.0f, 0.0f);
    Point C(0.0f, 5.0f);

    // C = B;
    // std::cout << "address B:    " << &B << "|   " << B.getX() << "  " << B.getY() << std::endl;
    // std::cout << "address C:    " << &C << "|   " << C.getX() << "  " << C.getY() << std::endl;
    Point P1(1.0f, 1.0f); // inside        true
    Point P2(6.0f, 6.0f); // outside       false
    Point P3(0.0f, 0.0f); // on point A    false
    Point P4(2.5f, 2.5f); // on side BC    false
    Point P5(3.0f, 0.0f); // on side AB    false
    Point P6(1.0f, 4.0f); // outside       false
    Point P7(2.5f, 1.25f); // inside       true
    Point P8(5.0f, 5.0f); // outside       false
    Point P9(-1.0f, -1.0f); // outside     false
    Point P10(0.0f, 2.5f); // on side CA   false

    showInData(A, B, C, P1);
    showRes(bsp(A, B, C, P1));
    showInData(A, B, C, P2);
    showRes(bsp(A, B, C, P2));
    showInData(A, B, C, P3);
    showRes(bsp(A, B, C, P3));
    showInData(A, B, C, P4);
    showRes(bsp(A, B, C, P4));
    showInData(A, B, C, P5);
    showRes(bsp(A, B, C, P5));
    showInData(A, B, C, P6);
    showRes(bsp(A, B, C, P6));
    showInData(A, B, C, P7);
    showRes(bsp(A, B, C, P7));
    showInData(A, B, C, P8);
    showRes(bsp(A, B, C, P8));
    showInData(A, B, C, P9);
    showRes(bsp(A, B, C, P9));
    showInData(A, B, C, P10);
    showRes(bsp(A, B, C, P10));
    std::cout << "Press any button to go in menu" << std::endl;
    if (getlineSafe() == "q")
        exit(0);
}

int main( void ) {
    std::string in;
    while (true)
    {
        cleanConsole();
        std::cout << BLUE << "Choose mode: t - test, m - manual, q - quit program" << RE << std::endl;
        in = getlineSafe();
         if (in == "t")
            testMode();
        else if (in == "m")
            manualMode();
        else if (in == "q")
            exit (0);
    }
    return 0;
}