/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 16:46:48 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/08/23 23:30:37 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#define RED "\033[1;31m"
#define YELLOW "\033[0;33m"
#define GREEN "\033[0;32m"
#define BLUE "\033[0;34m"
#define RE "\033[;0m"

#include <iostream>
#include <cmath>

class Fixed
{
    private:
        int fixed;
        static const int bits = 8;
    public:
        Fixed();
        Fixed(const int num);
        Fixed(const float num);
        ~Fixed();
        Fixed(const Fixed& other);
        Fixed&          operator=(const Fixed& other);
    
    // comparison operators: < > >= <= == !=
        Fixed&          operator>(const Fixed& other);
        Fixed&          operator<(const Fixed& other);
        Fixed&          operator>=(const Fixed& other);
        Fixed&          operator<=(const Fixed& other);
        Fixed&          operator==(const Fixed& other);
        Fixed&          operator!=(const Fixed& other);

    //arithmetic operators: + - * /
        Fixed&          operator+(cons Fixed& other);
        Fixed&          operator-(cons Fixed& other);
        Fixed&          operator*(cons Fixed& other);
        Fixed&          operator/(cons Fixed& other);

    //increment/decrement:  i++ i-- ++i --i
        Fixed&          operator++();
        Fixed&          operator--();
        Fixed&          operator++(int);
        Fixed&          operator--(int);
    
        static Fixed&   min(Fixed& obj1, Fixed& obj2) const;
        static const Fixed&   min(const Fixed& obj1, const Fixed& obj2) const;
        static Fixed&   max(Fixed& obj1, Fixed& obj2) const;
        static const Fixed&   max(const Fixed& obj1, const Fixed& obj2) const;
        int             getRawBits(void) const;
        void            setRawBits(int const raw);
        float           toFloat(void) const;
        int             toInt(void) const;
};
    std::ostream&   operator<<(std::ostream& os, const Fixed& instance);