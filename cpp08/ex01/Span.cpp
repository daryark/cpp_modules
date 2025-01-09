/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 22:40:25 by dyarkovs          #+#    #+#             */
/*   Updated: 2025/01/08 12:30:15 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(unsigned int n): arr(std::vector<int>) {}; //!need to understand, if i can make n elements vector in the moment of construction?

Span::~Span() {};

Span::Span(const Span& other): arr(other)