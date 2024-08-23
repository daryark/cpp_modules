/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 16:47:17 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/08/23 23:31:08 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

//Constructors
Fixed::Fixed(): fixed(0){}

Fixed::Fixed(const int num)
{
    this->fixed = num << this->bits;
}
Fixed::Fixed(const float num)
{
    this->fixed = roundf(num * (1 << this->bits));
}

Fixed::~Fixed(){}

Fixed::Fixed(const Fixed& other)
{
    *this = other;
}

// comparison operators: < > >= <= == !=
Fixed& Fixed::operator=(const Fixed& other)
{
    if (this != &other)
        this->fixed = other.getRawBits();
    return (*this);
}

// Fixed&  Fixed::operator>(const Fixed& other)
// {
    
// }

//arithmetic operators: + - * /
////

 //increment/decrement:  i++ i-- ++i --i
 ////

//overloading to os
std::ostream&   operator<<(std::ostream &os, const Fixed& instance)
{
    return (os << instance.toFloat());
}

static Fixed&   min(Fixed& obj1, Fixed& obj2)
{
    return (obj1 < obj2 ? obj1 : obj2);
}

//Comparison min/max
static const Fixed&   min(const Fixed& obj1, const Fixed& obj2)
{
    return (obj1 < obj2 ? obj1 : obj2);
}

static Fixed&   max(Fixed& obj1, Fixed& obj2)
{
    return (obj1 > obj2 ? obj1 : obj2);
}

static const Fixed&   max(const Fixed& obj1, const Fixed& obj2)
{
    return (obj1 > obj2 ? obj1 : obj2);
}

//other methods
int    Fixed::getRawBits(void) const
{
    return (this->fixed);
}

void    Fixed::setRawBits(int const raw)
{
    this->fixed = raw;
}

float   Fixed::toFloat(void) const
{
    return (roundf(this->fixed) / (1 << this->bits));
}

int   Fixed::toInt(void) const
{
    return (this->fixed >> this->bits);
}