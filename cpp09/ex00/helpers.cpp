/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 19:30:30 by dyarkovs          #+#    #+#             */
/*   Updated: 2025/06/29 16:47:44 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"


bool    isDateFormatValid(std::string& date)
{
    if (date.length() != 10)
        return false;
    int year;
    int month;
    int day;
    extractDate(date, year, month, day);
    if (year < 2009 || month > 12 || !isDayOfMonthValid(year, month, day))
        return false;
    return true;
}

bool    isDayOfMonthValid(int& y, int& m, int& d)
{
    if (m == 2)
    {
        if (isLeapYear(y))
            return d <= 29;
        return d <= 28;
    }
    else if (SHORT_MONTHS_MASK & (1 << m))
        return d <= 30;
    return d <= 31;
}
bool    isLeapYear(int y) {
    return (y % 4 == 0) && ( (y % 100 != 0) || (y % 400 == 0));
}

void    extractDate(std::string& date, int& y, int& m, int& d)
{
    std::string s_y;
    std::string s_m;
    std::string s_d;
    std::istringstream iss(date);
    std::getline(iss, s_y, '-');
    std::getline(iss, s_m, '-');
    iss >> s_d;
    y = atoi(s_y.c_str());
    m = atoi(s_m.c_str());
    d = atoi(s_d.c_str());
}

void    trimInPlace(std::string& s, std::string delim)
{
    std::size_t first = s.find_first_not_of(delim);
    std::size_t last = s.find_last_not_of(delim);
     if (first == std::string::npos)
        s.clear();
    else
        s = s.substr(first, last - first + 1);
}

// static void    printErrType(std::string type)
// {
//     if (type == "file")
//         std::cerr << RED << "Error opening file" << RE << std::endl;
//     else
//         std::cerr << RED << "Error" << RE << std::endl;
// }
