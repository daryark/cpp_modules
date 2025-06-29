/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 19:21:17 by dyarkovs          #+#    #+#             */
/*   Updated: 2025/06/29 17:33:16 by dyarkovs         ###   ########.fr       */
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
    std::string     file_name = "data copy.csv";
    std::ifstream    data_file(file_name.c_str());
    if (!data_file.is_open())
        throw std::runtime_error("Failed to open file: " + file_name);
    std::string    line;
    std::getline(data_file, line);
     if (line.compare("date,exchange_rate") != 0)
        throw std::runtime_error("Invalid file format");
    std::string    key;
    float          value;
    while (std::getline(data_file, line))
    {
        std::istringstream iss(line);
        std::getline(iss, key, ',');
        trimInPlace(key);
        if (!isDateFormatValid(key))
            throw std::runtime_error(std::string("Invalid format/date: ") + RED + key + RE);
        if (_bic_rates.find(key) != _bic_rates.end())
            throw std::runtime_error(std::string("Date duplicate exchange rates file: ") + file_name);
        iss >> value;
        if (value < 0)
        {
            std::ostringstream oss;
            oss << value;
            throw std::runtime_error(std::string("Invalid value: ") + RED + oss.str() + RE);
        }
        _bic_rates[key] = value;
    }
}

void    BitcoinExchange::exchange(const std::string& filename)
{
        std::ifstream   in_file(filename.c_str());
    if (!in_file.is_open())
        throw std::runtime_error("Failed to open file: " + filename);
    std::string line;
    std::getline(in_file, line);
    if (line.compare("date | value") != 0)
        throw std::runtime_error("Invalid file format" + filename);
    std::string key;
    float       value;
    while (std::getline(in_file, line))
    {
        std::istringstream iss(line);
        std::getline(iss, key, '|');
        trimInPlace(key);
        if (!isDateFormatValid(key))
            std::cerr << RED << "Error: bad input => " << key << RE << std::endl;
        iss >> value;
        if (value < 0)
        {
            std::cout << RED << "Error: not a positive number."<< RE << std::endl;
            continue ;
        }
        if (static_cast<long>(value) > std::numeric_limits<int>::max())
        {
            std::cout << RED << "Error: too large number." << RE << std::endl;
            continue ;
        }
        std::map<std::string, float>::iterator it = _bic_rates.lower_bound(key);
        if (it == _bic_rates.begin() && it->first != key)
        {
            std::cerr << RED << "No earlier date found" << RE << std::endl;
            continue ;
        }
        else if (it->first == key)
            std::cout << key << " => " << value << " = " << it->second * value << std::endl;
        else
            std::cout << key << " => " << value << " = " << (--it)->second * value << std::endl;

    }
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