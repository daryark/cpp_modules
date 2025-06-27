/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 19:21:17 by dyarkovs          #+#    #+#             */
/*   Updated: 2025/06/27 21:01:07 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
    std::ifstream    data_file("data.csv");
    if (!data_file.is_open())
        throw std::runtime_error("Failed to open file: " + data_file);
    init(data_file);
}

BitcoinExchange::~BitcoinExchange(){}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other): _to_exchange(other._to_exchange){}

BitcoinExchange&    BitcoinExchange::operator=(const BitcoinExchange& other)
{
    if (this != other)
        _to_exchange = other._to_exchange;
    return *this;
}

void    BitcoinExchange::init(const std::ifstream& data_file)
{
    //read lines
    //check format each line
    //check for no dup in dates
    //write into map key|value from iss
}

void    BitcoinExchange::exchange(const std::string& file)
{
        std::ifstream   in_file(file);
    if (!in_file.is_open())
        throw std::runtime_error("Failed to open file: " + in_file);
    //check each line on validity of formating and dates(no future, no too old)
    //exchange: find the date for each, exchange up to the rates
    //print output for each line
}

