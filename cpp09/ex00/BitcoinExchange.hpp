/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 19:13:30 by dyarkovs          #+#    #+#             */
/*   Updated: 2025/06/29 17:19:33 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <algorithm>
#include <map>
#include <sstream>
#include <fstream>
#include <string>
#include <limits>

#include "../colors.hpp"

#define SHORT_MONTHS_MASK ((1 << 4) | (1 << 6) | (1 << 9) | (1 << 11))
//fill 1 bit, on places(move at 4,6...places into the mask).
//(true) for the nums down: 11 9   6  4
//res:                      0101 0010 1000

class BitcoinExchange
{
private:
    std::map<std::string, float>  _bic_rates;

    void    init();
public:
    BitcoinExchange();
    ~BitcoinExchange();
    BitcoinExchange(const BitcoinExchange&);
    BitcoinExchange&    operator=(const BitcoinExchange&);

    void    exchange(const std::string&);
};

// static void printErrType(std::string type);
bool    isDateFormatValid(std::string&);
bool    isDayOfMonthValid(int& y, int& m, int& d);
void    extractDate(std::string& date, int& y, int& m, int& d);
bool    isLeapYear(int);
void    trimInPlace(std::string& , std::string delim = " \t\n\r\f\v");