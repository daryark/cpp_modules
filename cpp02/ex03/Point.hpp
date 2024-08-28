/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 17:10:48 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/08/28 17:03:33 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

class Point
{
    private:
        Fixed const x;
        Fixed const y;
    public:
        Point();
        Point(const float px, const float py);
        Point(const Point& other);
        Point& operator=(const Point& other);
        ~Point();

        float getY() const;
        float getX() const;
};
    bool bsp( Point const a, Point const b, Point const c, Point const point);