/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 16:47:17 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/08/22 22:17:54 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
    this->val = 0;
    std::cout << GREEN << "Default constructor called" << RE << std::endl;
}

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


//*expect ref(ref on real OBJ, not its pointer)
// Fixed& Fixed::operator=(const Fixed& other)
// {
//     if (this != &other)
//         this->val = other.val;
//     std::cout << "Copy assignment operator called" << std::endl;
//     return (*this); //*return unpointed obj - real obj with new value inside.
// }//*so the values inside the same ref will be update with the values that's been copied in it.