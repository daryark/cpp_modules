/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 23:17:18 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/08/14 20:07:53 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include <iostream>

bool	nameIsValid(std::string name);
bool	numberIsValid(std::string number);

Contact::Contact(){};

Contact::~Contact(){};

void Contact::fillContactInfo(Contact &contact)
{

	contact.setFieldInfo("First name	", contact.first_name, "name");
	contact.setFieldInfo("Last name	", contact.last_name, "name");
	contact.setFieldInfo("Nickname	", contact.nickname, "name");
	contact.setFieldInfo("Phone number	", contact.phone_number, "number");
	contact.setFieldInfo("Darkest secret	", contact.darkest_secret, "text");
}

void	Contact::setFieldInfo(std::string prompt, std::string &buf, std::string rule)
{
	bool valid = true;

	std::cout << YELLOW << prompt << RE;
	std::getline(std::cin, buf);
	if (buf.empty())
	{
		std::cout << RED << "No empty fileds accepted!" << RE << std::endl;
		valid = false;
	}
	if (valid)
	{
		if (rule == "name")
			valid = nameIsValid(buf);
		else if (rule == "number")
			valid = numberIsValid(buf);
	}
	if (!valid)
		setFieldInfo(prompt, buf, rule);
}

std::string	Contact::getFirstName()
{
	return (this->first_name);
}

std::string	Contact::getLastName()
{
	return (this->last_name);
}

std::string	Contact::getNickname()
{
	return (this->nickname);
}

std::string	Contact::getPhoneNumber()
{
	return (this->phone_number);
}

std::string	Contact::getDarkestSecret()
{
	return (this->darkest_secret);
}
