/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 13:59:58 by dyarkovs          #+#    #+#             */
/*   Updated: 2025/01/05 04:24:19 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int main( void )
{
    int iNums[] = {1, 2, 3, 4 ,5};
    int size = sizeof(iNums) / sizeof(*iNums);
    ::iter(iNums, size, ::print);
    std::cout << "-------------------------------\n";
    ::iter(iNums, size, ::increment);
    ::iter(iNums, size, ::print);
    std::cout << "-------------------------------\n";
}
//:: explicitly showes that the fn is in the GLOBAL NAMESPACE/SCOPE
//in case, when there is fn with the same name as a member of any other scopy (class, lib...)
//it will not cause ambigulity for the compiler