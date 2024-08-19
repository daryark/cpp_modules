/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 01:00:59 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/08/19 14:08:58 by dyarkovs         ###   ########.fr       */
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
    std::ifstream in_file(av[1]);

    if (!in_file.is_open())
        return (printError("file"));
    
    std::string s1 = av[2];
    std::string s2 = av[3];
    std::string file = av[1];
    
    std::string in_line;
    std::string out_line;
    size_t pos;
    
    std::string out_name = file + ".replace";
    std::ofstream out_file(out_name.c_str());

    while (std::getline(in_file, in_line))
    {
        out_line = in_line;
        pos = out_line.find(s1);
        while (pos != std::string::npos)
        {
            out_line = out_line.substr(0, pos) + s2 + out_line.substr(pos + s1.length());
            pos = out_line.find(s1, pos + s2.length());
        }
        out_file << out_line << std::endl;
    }
    out_file.close();
    in_file.close();
    return (0);
}