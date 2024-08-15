/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 18:58:14 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/08/15 00:05:49 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

std::string formatStr(std::string s)
{
    if (s.length() > PRINT_W)
        return(s.substr(0, PRINT_W - 1).append("."));
    else
        return (s);
}

void    printFormatRow(std::string *s, size_t size, std::string color)
{
    std::cout << color;
    for (size_t i = 0; i < size; i++)
        std::cout << std::setw(PRINT_W) << std::left << formatStr(s[i]) << " |";
    std::cout << RE << std::endl;
}

bool    nameIsValid(std::string name)
{
    
    if (name.length() < 2 || name.length() > 30)
    {
        std::cout << RED << "Name can only contain 2-30 symbols"
            << RE << std::endl;
        return (false);
    }
    for (int i = 0; name[i]; i++)
    {
        if (std::isdigit(name[i]))
        {
            std::cout << RED << "Field cannot contain digits" 
                << RE << std::endl;
            return (false);
        }
    }
    return (true);
}

bool    numberIsValid(std::string number)
{
    int i = 0;
    int n = 0;

    if ((char)number[0] == '+')
        i++;
    while (number[i])
    {
        if (std::isdigit(number[i]))
            n++;
        if (!std::isdigit(number[i]) && number[i] != ' ' && number[i] != '-')
        {
            std::cout << RED << "Field can contain only digits, \" \" or \"-\""
                << RE << std::endl;
            return (false);
        }
        i++;
    }
    if (n < 7 || n > 15)
    {
        std::cout << RED << "Field length allowed 7-16 digits"
            << RE << std::endl;
        return (false);
    }
    return (true);
}

static size_t    validateSearchData()
{
    std::string in;
	size_t id;

	std::cout << YELLOW << "SEARCH contact id:  " << RE;
	std::getline(std::cin, in);
    if (std::cin.eof())
            exit(0);
	std::stringstream ss(in);
	ss >> id;
	if (ss.fail() || !ss.eof() || id >= PBOOK_LEN)
	{
        if (ss.fail() || !ss.eof())
    		std::cout << RED << "Not valid input. Please type positive number"
			    << RE << std::endl;
        else
            std::cout << RED << "Please type id in range 0-7" << RE << std::endl;
        std::cin.clear();
        return (validateSearchData());
	}
	return (id);
    }

int main(void)
{
    PhoneBook       pB;
    std::string     in;
    size_t          id = 0;

    while (true)
    {
        std::cout << BLUE << "type the command (ADD, SEARCH, EXIT ):    " << GREEN;
        std::getline(std::cin, in);
        if (std::cin.eof())
            exit(0);
        std::cout << std::endl << RE;
        if(in == "ADD")
            pB.addContact(&id);
        else if (in == "SEARCH")
            pB.searchContact(validateSearchData());
        else if (in == "CONTACTS")
            pB.showContacts();
        else if (in == "EXIT")
            break ;
        else
            std::cout << RED << "Read the fluffy manual 🤡. Accepted commands 🔽"
                << RE << std::endl;
    }
}
