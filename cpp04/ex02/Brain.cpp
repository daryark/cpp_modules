/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 21:22:08 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/09/13 23:45:28 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
#include <sstream>

Brain::Brain()
{
    for (int i = 0; i < 100; i++)
    {    
        std::stringstream ss;
        ss << i;
        _ideas[i] = ss.str() + " idea";
    }
    std::cout << GREEN << "Brain 🧠" << RE
    << " default constructor" << std::endl;
}

Brain::~Brain()
{
    std::cout << GREEN << "Brain 🧠" <<  RE
    << " destructor" << std::endl;
}

Brain::Brain(const Brain& other)
{
    if (this != &other)
        *this = other;
    std::cout << GREEN << "Brain 🧠" << RE
    << " copy constuctor" << std::endl;
}

Brain& Brain::operator=(const Brain& other)
{
    std::cout << GREEN << "Brain 🧠" << RE
    << " copy assignment operator" << std::endl;
    if (this != &other)
    {
        for (int i = 0; i < 100; i++)
            _ideas[i] = other._ideas[i];
    }
    return (*this);
}

const std::string    Brain::getIdeaByIdx(int idx) const
{
    std::string err = "no idea by that idx" + idx;
    if (idx < 0 || idx > 99)
        return (err);
    else
        return (_ideas[idx]);
}

void    Brain::setIdeaByIdx(std::string& idea, int idx)
{
    if (idx >= 0 && idx < 100)
        _ideas[idx] = idea;
}