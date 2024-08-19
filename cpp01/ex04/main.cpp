/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 01:00:59 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/08/19 02:45:18 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <sstream>

#define RED "\033[1;31m"
#define YELLOW "\033[1;33m"
#define GREEN "\033[1;32m"
#define RE "\033[;0m"

static bool    printError(std::string type)
{
    if (type == "structure")
        std::cerr << RED << "Error: <filename> <string_to_find> <subst_string>" << RE << std::endl;
    else if (type == "file")
        std::cerr << RED << "Error opening file" << RE << std::endl;
    else
        std::cerr << RED << "Error" << RE << std::endl;
    return (true);
}

int main(int ac, char **av)
{
    if (ac != 4)
        return (printError("structure"));
    std::ifstream inFile(av[1]);
    if (!inFile.is_open())
        return (printError("file"));
    std::string s1 = av[2];
    std::string s2 = av[3];
    std::string file = av[1];
    std::string outFile = file + ".replace";
    std::string in_line;
    std::string out_line;
    while (std::getline(inFile, in_line))
    {
        if (in_line.find(s1))
            out_line = in_line.copy((char *)in_line.c_str(), in_line.length());
        std::cout << out_line << std::endl;
        //outFile += out_line
    }
    // file.close();
    return (0);
}