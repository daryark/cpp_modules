/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 23:17:23 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/08/14 18:47:31 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// first name, last name, nickname, phone number, and
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

#pragma once
#include <string>

#define RED "\033[1;31m"
#define YELLOW "\033[1;33m"
#define GREEN "\033[1;32m"
#define BLUE "\033[1;34m"
#define RE "\033[;0m"

class Contact
{
  public:
	std::string first_name;

  private:
	std::string last_name;
	std::string nickname;
	std::string phone_number;
	std::string darkest_secret;

  public:
	Contact();
	~Contact();
	void fillContactInfo(Contact &contact);
	void setFieldInfo(std::string prompt, std::string &buf, std::string rule);

	std::string getFirstName();
	std::string getLastName();
	std::string getNickname();
	std::string getPhoneNumber();
	std::string getDarkestSecret();
};
