/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 17:18:22 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/08/23 13:19:54 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// int main(void) 
// {
//     Fixed a;
//     std::cout << a.getRawBits() << BLUE << "    a" << RE << std::endl << std::endl;
//     a.setRawBits(2);
//     Fixed b(a);
//     std::cout << a.getRawBits() << BLUE << "    a" << RE << std::endl;
//     std::cout << b.getRawBits() << BLUE << "    b" << RE << std::endl << std::endl;

//     b.setRawBits(4);
//     Fixed c;
//     std::cout << c.getRawBits() << BLUE << "    c" << RE << std::endl << std::endl;
//     c = b;
//     std::cout << a.getRawBits() << BLUE << "    a" << RE << std::endl;
//     std::cout << b.getRawBits() << BLUE << "    b" << RE << std::endl;
//     std::cout << c.getRawBits() << BLUE << "    c" << RE << std::endl;
//     return 0;
// }

int main( void ) {
Fixed a;
Fixed b( a );
Fixed c;
c = b;
std::cout << a.getRawBits() << std::endl;
std::cout << b.getRawBits() << std::endl;
std::cout << c.getRawBits() << std::endl;
return 0;
}