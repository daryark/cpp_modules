/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 16:44:07 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/08/10 14:43:46 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Contact.hpp"

class PhoneBook
{
    Contact contacts[8];
    int     amnt;
    
    public:
        PhoneBook();
    void    addContact(Contact contact);
    bool    searchContact(unsigned int id);
    void    exitPhoneBook();
        ~PhoneBook();
};