/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyarkovs <dyarkovs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 15:18:08 by dyarkovs          #+#    #+#             */
/*   Updated: 2024/07/09 15:58:47 by dyarkovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(int ac, char **av)
{
	int	i;
	int	j;

	i = 0;
	if (ac == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	while (av[++i])
	{
		j = -1;
		while (av[i][++j])
			std::cout << (char)toupper(av[i][j]);
		std::cout << " ";
	}
	std::cout << std::endl;
	return (0);
}
