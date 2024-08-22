/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 16:47:17 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/08/22 22:32:58 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
    this->val = 0;
    std::cout << GREEN << "Default constructor called" << RE << std::endl;
}

// Fixed::Fixed(const int num)
// {
//     this->val = 0;
//     std::cout << GREEN << "INT Constructor called" << RE << std::endl;
// }

// Fixed::Fixed(const float num)
// {
//     this->val = 0;
//     std::cout << GREEN << "FLOAT Constructor called" << RE << std::endl;
// }

Fixed::~Fixed()
{
    std::cout << RED << "Destructor called" << RE << std::endl;
}

Fixed::Fixed(const Fixed& other): val(other.val)
{
    std::cout << YELLOW << "Copy constructor called" << RE << std:: endl;
}

Fixed& Fixed::operator=(const Fixed& other)
{
    if (this != &other)
        this->val = other.val;
    std::cout << YELLOW << "Copy assignment operator called" << RE << std::endl;
    return (*this);
}

int    Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called ";
    return (this->val);
}

void    Fixed::setRawBits(int const raw)
{
    std::cout << "setRawBits member function called " << std::endl;
    this->val = raw;
}

float   toFloat(void) const
// {

// }