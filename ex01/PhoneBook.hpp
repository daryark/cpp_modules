/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 16:44:07 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/08/14 13:59:55 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>
#include "Contact.hpp"

#define PBOOK_LEN   8
#define PRINT_W     10


class PhoneBook
{
    private:
        Contact contacts[8];
    public:
    PhoneBook();
    ~PhoneBook();
    void    addContact(size_t *id);
    void    printContactById(size_t id);
    void    searchContact(size_t id);
    void    showContacts();
    // void    exitPhoneBook();
};