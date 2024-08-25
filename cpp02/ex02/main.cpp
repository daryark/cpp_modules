/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 17:18:22 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/08/25 14:02:48 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"


int main( void ) {
Fixed a;
Fixed const b( Fixed( 5.05f ) * Fixed( 2 ));
std::cout << a << std::endl;
std::cout << ++a << std::endl;
std::cout << a << std::endl;
std::cout << a++ << std::endl;
std::cout << a << std::endl;

std::cout << b << std::endl;
// std::cout << "a > b:    " << (a > b) << std::endl;
// std::cout << "a < b:    " << (a < b) << std::endl;
// std::cout << "a >= b:    " << (a >= b) << std::endl;
// std::cout << "a <= b:    " << (a <= b) << std::endl;
// std::cout << "a == b:    " << (a == b) << std::endl;
// std::cout << "a != b:    " << (a != b) << std::endl;
std::cout << Fixed::max( a, b ) << std::endl;
return 0;
}