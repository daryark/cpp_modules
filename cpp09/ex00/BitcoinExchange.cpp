/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 19:21:17 by dyarkovs          #+#    #+#             */
/*   Updated: 2025/06/29 23:39:04 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
    init();
}

BitcoinExchange::~BitcoinExchange(){}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other): _bic_rates(other._bic_rates){}

BitcoinExchange&    BitcoinExchange::operator=(const BitcoinExchange& other)
{
    if (this != &other)
        _bic_rates = other._bic_rates;
    return *this;
}

void    BitcoinExchange::init()
{
    std::string     filename = "data.csv";
    std::ifstream   data_file(filename.c_str());
    std::string    line;
    std::getline(data_file, line);
    checkFFormat(line, "date,exchange_rate", filename);
    std::string     key;
    float           value;
    while (std::getline(data_file, line))
    {
        const char* err = parseCheckLine(line, key, value, ',');
        if (err != NULL)
            throw std::runtime_error(err);
        _bic_rates[key] = value;
    }
}

void    BitcoinExchange::exchange(std::string filename)
{
    std::ifstream   in_file(filename.c_str());
    checkOpenFS(filename, in_file);
    std::string line;
    std::getline(in_file, line);
    checkFFormat(line, "date | value", filename);
    std::string key;
    float       value;
    while (std::getline(in_file, line))
    {
        std::map<std::string, float>::iterator it;
        const char* err = parseCheckLine(line, key, value, '|');
        if (err == NULL)
        {
            it = _bic_rates.lower_bound(key);
            if (it == _bic_rates.begin() && it->first != key)
            err = ERR_OLD_DATE;
        }
        if (err != NULL)
        {
            std::cerr << RED << err;
            if (std::string(err) == ERR_BAD_DATE)
            std::cerr << " => " << key;
            std::cout << RE << std::endl;
            continue ;
        }
        else if (it->first != key)
        --it;
        std::cout << key << " => " << value << " = " << it->second * value << std::endl;
    }
}

const char*    BitcoinExchange::parseCheckLine(std::string& l, std::string& k, float& v, char d)
{
    std::istringstream iss(l);
    std::getline(iss, k, d);
    trimInPlace(k);
    if (!isDateFormatValid(k))
        return  ERR_BAD_DATE;
    if (d == ',' && _bic_rates.find(k) != _bic_rates.end())
        return ERR_DUP;
    if (iss.peek() == EOF)
        return ERR_NO_VAL;
    iss >> v;
    if (v < 0)
        return ERR_NEGATIVE;
    if (v > 1000 && d == '|')
        return ERR_BIG_N;
    return NULL;
}



//* std::getline(std::istream& is, std::string& s, char delim = '\n');
//* is - any type of stream(std::cin, std::ifstream, std::istringstream...)
//* s - destination to read the line into
//* delim - optionally different delimeter, default - newline
//  std::string    line;
//  std::string    key;
//  float          value;
// while (std::getline(data_file, line)) //takes line from file
// {
//     std::istringstream iss(line);//put line into stream
//     std::getline(iss, key, ','); take from stream until ','
//     iss >> value; //still left line after ',' in the stream, take it out
//     std::cout << key << " " << value << std::endl;
// }