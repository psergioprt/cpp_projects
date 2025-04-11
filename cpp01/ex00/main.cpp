/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauldos- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 15:34:07 by pauldos-          #+#    #+#             */
/*   Updated: 2025/04/11 11:51:09 by pauldos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(int argc, char *argv[])
{
	(void)argc;
	
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
