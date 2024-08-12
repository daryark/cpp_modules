/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 16:43:32 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/08/12 14:45:57 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <string>

//constructor (define, whatever is needed in the class for start)
PhoneBook::PhoneBook()
{
    this->amnt = 0;
    std::cout << "PhoneBook constructdor called" << std::endl;
};
PhoneBook::~PhoneBook()
{
    std::cout << "PhoneBook destructor called" << std::endl;
};

// void    PhoneBook::addContact(Contact contact)
// {
//     if (this->amnt == 8)
//         this->amnt = 0;
//     this->contacts[this->amnt] = contact;
//     this->amnt++;
// }

bool PhoneBook::searchContact(unsigned int id)
{
    if (id < 1 || id > 8)
        std::cout << "No contact with id: " << id << std::endl;
    else
        std::cout << "GET THE CONTACT" << std::endl;
    return (id >= 1 && id <= 8);
}


int main(int ac, char **av)
{
    PhoneBook pB;
    std::string in;

    do
    {
        std::cout << "type the command: ADD, SEARCH or EXIT accepted" << std::endl;
        std::getline(std::cin, in);
    } while (in == pB.ADD || in == pB.SEARCH || in == pB.DELETE); //ADD = 0, SEARCH = 1, DELETE = 2/ in -> string type!!!

}
