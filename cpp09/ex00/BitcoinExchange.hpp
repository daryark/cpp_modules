/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 19:13:30 by dyarkovs          #+#    #+#             */
/*   Updated: 2025/07/06 16:55:55 by dyarkovs         ###   ########.fr       */
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

#define ERR_BAD_DATE "Error: bad input"
#define ERR_OLD_DATE "Error: Old date"
#define ERR_NEGATIVE "Error: not a positive number"
#define ERR_BIG_N "Error: too large number"
#define ERR_DUP "Error: duplicate of the date"
#define ERR_NO_VAL "Error: missing value"

class BitcoinExchange
{
private:
    std::map<std::string, float>  _bic_rates;

    void    init();
    const char*  parseCheckLine(std::string& l, std::string& k, float& v, char d);
public:
    BitcoinExchange();
    ~BitcoinExchange();
    BitcoinExchange(const BitcoinExchange&);
    BitcoinExchange&    operator=(const BitcoinExchange&);

    void    exchange(std::string);
};

const char* ifValidWriteNum(std::string s, float& value, char file_delim);
bool        isDateFormatValid(std::string& date_str);
bool        isDayOfMonthValid(int& y, int& m, int& d);
void        extractDate(std::string& date, int& y, int& m, int& d);
bool        isLeapYear(int y);
void        trimInPlace(std::string& , std::string delim = " \t\n\r\f\v");
void        checkOpenFS(std::string& n, std::ifstream& f);
void        checkFFormat(std::string s1, std::string s2, std::string& filename);


// #define SHORT_MONTHS_MASK ((1 << 4) | (1 << 6) | (1 << 9) | (1 << 11))
//fill 1 bit, on places(move at 4,6...places into the mask).
//(true) for the nums down: 11 9   6  4
//res:                      0101 0010 1000