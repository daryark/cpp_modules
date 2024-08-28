/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 17:05:16 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/08/28 15:58:01 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(): x(0), y(0){}

Point::Point(const float px, const float py): x(px), y(py){}

Point::Point(const Point& other): x(other.getX()), y(other.getY()){}

Point&  Point::operator=(const Point& other)
{
    (void) other;
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
