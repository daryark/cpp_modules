/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 16:44:07 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/08/12 14:42:39 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
// #include "Contact.hpp"

class PhoneBook
{
    // Contact contacts[8];
    private:
        int     amnt;
    public:
        enum Action
        {
            ADD,
            SEARCH,
            DELETE
        };
    
    public:
    PhoneBook();
    ~PhoneBook();
    // void    addContact(Contact contact);
    bool    searchContact(unsigned int id);
    // void    exitPhoneBook();
};