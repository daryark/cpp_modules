/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 16:47:17 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/08/23 20:22:12 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
    this->fixed = 0;
    std::cout << GREEN << "Default constructor called" << RE << std::endl;
}

Fixed::Fixed(const int num)
{
    // this->fixed = num * pow(2, this->bits); //2^8 (2^this->bits) // 256// - the same as num << bits
    this->fixed = num << this->bits;
    std::cout << GREEN << "Int constructor called" << RE << std::endl;
}

Fixed::Fixed(const float num)
{
    //this->fixed = round(num * pow(2 * this->bits)) // 256-decimal == 10000000-binary // the same, but bitwize op. faster for computer
    this->fixed = round(num * (1 << this->bits));
    std::cout << GREEN << "Float constructor called" << RE << std::endl;
}

Fixed::~Fixed()
{
    std::cout << RED << "Destructor called" << RE << std::endl;
}

Fixed::Fixed(const Fixed& other)
{
    std::cout << YELLOW << "Copy constructor called" << RE << std:: endl;
    *this = other;
}

Fixed& Fixed::operator=(const Fixed& other)
{
    std::cout << YELLOW << "Copy assignment operator called" << RE << std::endl;
    if (this != &other)
        this->fixed = other.getRawBits();
    return (*this);
}

std::ostream&   operator<<(std::ostream &os, const Fixed& instance)
{
    return (os << instance.toFloat());
}

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
    // return (this->fixed * pow(2, -(this->bits)));
    return (round(this->fixed) / (1 << this->bits));
}

int   Fixed::toInt(void) const
{
    // return (this->fixed / (1 << this->bits));
    return (this->fixed >> this->bits);
}