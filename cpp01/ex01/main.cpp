/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 21:13:09 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/08/19 21:53:32 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <cstdlib>

int main(void)
{
    std::string in;
    int         N;
    std::string name;

    std::cout << YELLOW << "<number> <name>:    " << RE;
    std::getline(std::cin, in);
    if (std::cin.eof())
            exit(0);
    std::istringstream iss(in);
    if (!(iss >> N) || !(iss >> name))
    {
        std::cerr << RED << "Expected input format <number> <name>" << RE << std::endl;
        return (1);
    }
    if (N <= 0)
    {
        std::cerr << RED << "Only positive number amount and name string"
            << RE << std::endl;
        return (1);
    }
    Zombie *zombies = zombieHorde(N, name);
    for(int i = 0; i < N; i++)
        zombies[i].announce();
    delete []zombies;
    return (0);
}
