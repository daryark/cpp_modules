/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 21:22:25 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/09/13 23:43:29 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#define GREEN "\033[0;32m"
#define RE "\033[;0m"

#include <iostream>

class Brain
{
protected:
    std::string _ideas[100];
public:
        Brain();
        ~Brain();
        Brain(const Brain& other);
        Brain&              operator=(const Brain& other);
        const std::string   getIdeaByIdx(int idx) const;
        void                setIdeaByIdx(std::string& idea, int idx);
};
