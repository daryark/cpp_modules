/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 16:43:32 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/08/14 20:06:45 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

void        printFormatRow(std::string *s, size_t size, std::string color = RE);
std::string formatStr(std::string s);

PhoneBook::PhoneBook()
{
	std::cout << "PhoneBook constructdor called" << std::endl;
};
PhoneBook::~PhoneBook()
{
	std::cout << "PhoneBook destructor called" << std::endl;
};
void PhoneBook::addContact(size_t *id)
{
	Contact	new_contact;

	new_contact.fillContactInfo(new_contact);
	if ((*id) == PBOOK_LEN)
		(*id) = 0;
	this->contacts[(*id)] = new_contact;
	std::cout << YELLOW << this->contacts[(*id)].first_name << RE << " first name" << std::endl;
	(*id)++;
}

void	PhoneBook::printContactById(size_t i)
{
	std::stringstream ss;
 
	std::string	headers[] = {"Index", "First Name", "Last Name", "Phone number"};
	printFormatRow(headers, 4, YELLOW);
	ss << i;
	std::string contact[] = {ss.str(), this->contacts[i].getFirstName(),
		this->contacts[i].getLastName(), this->contacts[i].getPhoneNumber()};
	printFormatRow(contact, 4);
}

void PhoneBook::searchContact(size_t id)
{
	if (this->contacts[id].getFirstName().empty())
		std::cout << RED << "No contact with id: " << id << RE << std::endl;
	else
		this->printContactById(id);
}

void PhoneBook::showContacts()
{
	std::stringstream ss;

	if (this->contacts[0].getFirstName().empty())
	{
		std::cout << RED << "You don't have contacts yet, ADD some."
			<< RE << std::endl;
		return ;
	}
		std::string	row[] = {"Index", "First Name", "Last Name", "Nickname",
			"Phone number", "Darkest secret"};
		printFormatRow(row, 6, YELLOW);
	for (int i = 0; i < PBOOK_LEN
		&& !this->contacts[i].getFirstName().empty(); i++)
	{
		ss << i;
		std::string row[] = {ss.str(), this->contacts[i].getFirstName(),
			this->contacts[i].getLastName(),this->contacts[i].getNickname(),
			this->contacts[i].getPhoneNumber(), this->contacts[i].getDarkestSecret()};
		printFormatRow(row, 6);
		ss.str("");
        ss.clear();
	}
}
