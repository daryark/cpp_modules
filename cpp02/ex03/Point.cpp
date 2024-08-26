/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 17:05:16 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/08/26 20:29:18 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(): x(0), y(0){}
Point::Point(const float px, const float py): x(px), y(py){}
Point::Point(const Point& other)
{
    *this = other;
}
Point&  Point::operator=(const Point& other)
{
    if (this != &other)
    {
        (Fixed)this->x = other.x;
        (Fixed)this->y = other.y;
    }
    return (*this);
}
Point::~Point(){}

float Point::getX() const
{
    return (this->x.toFloat());
}
float Point::getY() const
{
    return (this->y.toFloat());
}
