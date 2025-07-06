/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 19:30:30 by dyarkovs          #+#    #+#             */
/*   Updated: 2025/07/06 17:05:51 by dyarkovs         ###   ########.fr       */
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
    if (month > 12 || !isDayOfMonthValid(year, month, day))
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

const char* ifValidWriteNum(std::string s, float& v, char d)
{
    
    if (s.empty())
        return ERR_NEGATIVE;
    bool dot = false;
    for (size_t i = 0; i < s.length(); i++)
    {
        if (s[i] == '.')
        {
            if (dot)
                return ERR_NEGATIVE;
            dot = true;
            continue ;
        }
        if (!std::isdigit(s[i]))
            return ERR_NEGATIVE;
    }
    std::istringstream niss(s);
    niss >> v;
    if (v < 0)
        return ERR_NEGATIVE;
    if (v > 1000 && d == '|')
        return ERR_BIG_N;
    return NULL;
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

void    checkOpenFS(std::string& f, std::ifstream& ifs)
{
    if (!ifs.is_open())
        throw std::runtime_error("Failed to open file: " + f);
}

void    checkFFormat(std::string s1, std::string s2, std::string& filename)
{
    if (s1.compare(s2) != 0)
        throw std::runtime_error("Invalid file format" + filename);
}

