/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 16:47:17 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/08/23 13:27:36 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
    this->fixed = 0;
    std::cout << GREEN << "Default constructor called" << RE << std::endl;
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

int    Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called " << std::endl;
    return (this->fixed);
}

void    Fixed::setRawBits(int const raw)
{
    std::cout << "setRawBits member function called " << std::endl;
    this->fixed = raw;
}


//*expect ref(ref on real OBJ, not its pointer)
// Fixed& Fixed::operator=(const Fixed& other)
// {
//     std::cout << "Copy assignment operator called" << std::endl;
//     if (this != &other)
//         this->fixed = other.fixed;
//     return (*this); //*return unpointed obj - real obj with new value inside.
// }//*so the values inside the same ref will be update with the values that's been copied in it.