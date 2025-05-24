/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauldos- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 14:23:52 by pauldos-          #+#    #+#             */
/*   Updated: 2025/05/24 18:54:45 by pauldos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Karen.hpp"
#include <iostream>

int	main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cout << "Usage: <command> <choice> - 2 arguments needed" << std::endl;
		return (1);
	}
	std::string level = argv[1];
	int	index = -1;
	int	i = 0;

	std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	while (i < 4)
	{
		if (level == levels[i])
		{
			index = i;
			break ;
		}
		i++;
	}

	Karen karen;

	switch(index)
	{
		case 0:
			karen.complain("DEBUG");
			//Intentional fallthrough
		case 1:
			karen.complain("INFO");
			//Intentional fallthrough
		case 2:
			karen.complain("WARNING");
			//Intentional fallthrough
		case 3:
			karen.complain("ERROR");
			break ;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	}
	return (0);
}
