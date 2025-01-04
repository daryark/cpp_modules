/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 19:26:49 by dyarkovs          #+#    #+#             */
/*   Updated: 2025/01/04 21:20:16 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream> 
#include <stdint.h> //uintptr_t

struct Data
{
    unsigned int    id;
    std::string     content;
};


class Serializer
{
private:
    Serializer();
    Serializer(const Serializer& other);
    Serializer& operator=(const Serializer& other);

public:
    ~Serializer();
    static uintptr_t   serialize(Data* ptr);
    static Data*       deserialize(uintptr_t raw);
};
