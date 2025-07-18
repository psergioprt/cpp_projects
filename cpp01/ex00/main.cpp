/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauldos- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 15:34:07 by pauldos-          #+#    #+#             */
/*   Updated: 2025/05/23 19:25:21 by pauldos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

int	main(int argc, char *argv[])
{
	if (argc == 2)
	{
		Zombie	*myZombie;

		myZombie = newZombie(argv[1]);
		myZombie->announce();
		delete myZombie;

		std::cout << "Creating a stack-allocated Zombie: " << std::endl;
		randomChump(argv[1]);
	}
	else
		std::cout << "No argument found!\n";
	return (0);
}
