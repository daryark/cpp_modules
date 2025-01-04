/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 21:51:00 by dyarkovs          #+#    #+#             */
/*   Updated: 2025/01/05 00:09:52 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

Base*   generate(void)
{
    std::cout << "generate" << std::endl;
    srand(time(NULL));
    int n = rand() % 3;
    if (n == 1)
        return new A;
    else if (n == 2)
        return new B;
    else
        return new C;
}

//! with *
//If the dynamic_cast fails, it simply returns a nullptr instead of throwing an exception.
//This is because pointers naturally have the ability to represent the absence of a valid object using nullptr.
void   identify(Base* p)
{
    if (dynamic_cast<A*>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "C" << std::endl;
    else
        std::cout << "not identified";
}

//! with &
//If the dynamic_cast fails (i.e., the object cannot be safely cast to the target type), it throws a std::bad_cast exception.
//This happens because references cannot represent a "null" or invalid value, so an exception is the only way to indicate failure.
void   identify(Base& p)
{
    try {
        (void)dynamic_cast<A&>(p); //to overpass err: "expression result not used" use (void)
        std::cout << "A" << std::endl;
        return ;
    } catch (...) {}
    try {
        (void)dynamic_cast<B&>(p);
        std::cout << "B" << std::endl;
        return ;
    } catch (...) {}
    try {
        (void)dynamic_cast<C&>(p);
        std::cout << "C" << std::endl;
        return ;
    } catch (...) {
        std::cout << "not identified";
    }
}

int main(void)
{
    Base* base = generate();
    identify(*base);
    identify(*base);
    return 0;
}