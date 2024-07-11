/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 23:17:23 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/07/11 00:29:37 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//first name, last name, nickname, phone number, and
// darkest secret
//* A saved contact can’t have empty fields.
// class Contact
// {
//     public:
//     char    *first_name;
//     char    *last_name;
//     unsigned int    id;

//     private:
//     char *darkest_secret;

// }

class Contact
{
private:
    char    *first_name;
    char    *last_name;
    unsigned int    id;
    char *darkest_secret;

public:
    Contact(/* args */);
    ~Contact();
};

Contact::Contact(/* args */)
{
}

Contact::~Contact()
{
}
