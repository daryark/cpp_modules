/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 21:13:09 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/08/18 22:43:39 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
    std::string in;
    int         N;
    std::string name;

    std::cout << YELLOW;
    std::getline(std::cin, in);
    std::cout << RE;
     std::istringstream iss(in);
    if (!(iss >> N) || !(iss >> name))
    {
        std::cout << RED << "Expected input format <number> <name>" << RE << std::endl;
        return (1);
    }
    if (N <= 0)
    {
        std::cout << RED << "Only positive number amount and name string"
            << RE << std::endl;
        return (1);
    }
    Zombie *zombies = zombieHorde(N, name);
    for(int i = 0; i < N; i++)
        zombies[i].announce();
    delete []zombies;
    return (0);
}
