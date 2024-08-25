/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 16:47:17 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/08/25 14:02:08 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

//Constructors
Fixed::Fixed(): fixed(0){}

Fixed::Fixed(const int num): fixed(num << this->bits){}

Fixed::Fixed(const float num): fixed(roundf(num * (1 << this->bits))){}

Fixed::~Fixed(){}

Fixed::Fixed(const Fixed& other)
{
    *this = other;
}

//*within the same instance of the class it's better to use direct access: this->fixed
//*to not make extra call of the getter fn.
//*to the other instance we access with getter to not violate the rule of incapsulation: other.getRawBits()
//*🔽
// comparison operators: =  < > >= <= == !=
Fixed& Fixed::operator=(const Fixed& other)
{
    if (this != &other)
        this->fixed = other.getRawBits();
    return (*this);
}

bool  Fixed::operator>(const Fixed& other) const
{
    return (this->fixed > other.getRawBits());
}

bool  Fixed::operator<(const Fixed& other) const
{
    return (this->fixed < other.getRawBits());
}

bool  Fixed::operator>=(const Fixed& other) const
{
    return (this->fixed >= other.getRawBits());
}

bool  Fixed::operator<=(const Fixed& other) const
{
    return (this->fixed <= other.getRawBits());
}

bool  Fixed::operator==(const Fixed& other) const
{
    return (this->fixed == other.getRawBits());
}

bool  Fixed::operator!=(const Fixed& other) const
{
    return (!(*this == other));
}

//arithmetic operators: + - * /
//*here we need to add standard types and so then 
//*we put result num to copy constructor of new instance
//*where it transferred to fixed again, inside.
Fixed  Fixed::operator+(const Fixed& other)
{
    return (Fixed(this->toFloat() + other.toFloat()));
}

Fixed  Fixed::operator-(const Fixed& other)
{
    return (Fixed(this->toFloat() - other.toFloat()));
}

Fixed  Fixed::operator*(const Fixed& other)
{
    return (Fixed(this->toFloat() * other.toFloat()));
}

Fixed  Fixed::operator/(const Fixed& other)
{
    return (Fixed(this->toFloat() / other.toFloat()));
}

 //increment/decrement:  i++ i-- ++i --i
 //*adds 1 bit, not 1.0 real num to the float/int value when converted back
 //* in that case to add real 1.0 you add 2^this->bits = 2^8 = 256
 Fixed&     Fixed::operator++()
 {
    ++this->fixed;
    return  (*this);
 }

 Fixed      Fixed::operator++(int)
 {
    Fixed   tmp(*this);
    this->fixed++;
    return  (tmp);
 }

 Fixed&     Fixed::operator--()
 {
    --this->fixed;
    return  (*this);
 }

 Fixed     Fixed::operator--(int)
 {
    Fixed   tmp(*this);
    this->fixed--;
    return  (tmp);
 }

//overloading to output
std::ostream&   operator<<(std::ostream &os, const Fixed& instance)
{
    return (os << instance.toFloat());
}

//Comparison min/max
Fixed&   Fixed::min(Fixed& obj1, Fixed& obj2)
{
    return (obj1 < obj2 ? obj1 : obj2);
}

const Fixed&   Fixed::min(const Fixed& obj1, const Fixed& obj2)
{
    return (obj1 < obj2 ? obj1 : obj2);
}

Fixed&   Fixed::max(Fixed& obj1, Fixed& obj2)
{
    return (obj1 > obj2 ? obj1 : obj2);
}

const Fixed&   Fixed::max(const Fixed& obj1, const Fixed& obj2)
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