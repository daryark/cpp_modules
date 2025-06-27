/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 19:13:30 by dyarkovs          #+#    #+#             */
/*   Updated: 2025/06/27 21:03:38 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <algorithm>
#include <map>

#include "../colors.hpp"

class BitcoinExchange
{
private:
    std::map<std::string, float>  _to_exchange;

    void    init(const std::ifstream&);
    //if date is valid (Range of date);
public:
    BitcoinExchange();
    ~BitcoinExchange();
    BitcoinExchange::BitcoinExchange(const BitcoinExchange&);
    BitcoinExchange&    operator=(const BitcoinExchange&);

    void    exchange(const std::string&);
};

// static void throwErrType(std::string type);
bool    isDateFormatValid(const std::string&);