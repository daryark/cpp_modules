/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 14:16:33 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/08/19 15:49:49 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

#define RED "\033[1;31m"
#define YELLOW "\033[1;33m"
#define GREEN "\033[1;32m"
#define BLUE "\033[1;34m"
#define GREY "\033[1;30m"
#define RE "\033[;0m"

class Harl
{
  private:
    void    Debug();
    void    Info();
    void    Warning();
    void    Error();

  public:
	Harl();
	~Harl();
    void    complain(std::string level);
};
