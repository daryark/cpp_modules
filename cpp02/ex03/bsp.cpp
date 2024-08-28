/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 17:05:44 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/08/28 17:37:56 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const p)
{
    // z1 = (b_x - a_x) * (p_y - a_y) - (b_y - a_y) * (p_x - a_x)
    Fixed z1 = (b.getX() - a.getX()) * (p.getY() - a.getY()) - \
        (b.getY() - a.getY()) * (p.getX() - a.getX());
    // z2 = (c_x - b_x) * (p_y - b_y) - (c_y - b_y) * (p_x - b_x)
    Fixed z2 = (c.getX() - b.getX()) * (p.getY() - b.getY()) - \
        (c.getY() - b.getY()) * (p.getX() - b.getX());
    // z3 = (a_x - c_x) * (p_y - c_y) - (a_y - c_y) * (p_x - c_x)
    Fixed z3 = (a.getX() - c.getX()) * (p.getY() - c.getY()) - \
    (a.getY() - c.getY()) * (p.getX() - c.getX());

    std::cout << BLUE << "  z1: " << z1 << "    z2: " << z2 << "    z3: " << z3 << RE << std::endl;
    return ((z1 > 0 && z2 > 0 && z3 > 0) || (z1 < 0 && z2 < 0 && z3 < 0));
}