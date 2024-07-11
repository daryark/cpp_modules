/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 16:44:07 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/07/11 00:31:25 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Contact.hpp"

class PhoneBook
{
    private:
        Contact contacts[8];
        int     amnt;
    
    public:
        PhoneBook();
    void    addContact(Contact contact);
    bool    searchContact(unsigned int id);
    void    exitPhoneBook();
        ~PhoneBook();
};