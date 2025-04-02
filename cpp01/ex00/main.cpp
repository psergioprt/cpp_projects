/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauldos- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 15:34:07 by pauldos-          #+#    #+#             */
/*   Updated: 2025/04/02 15:54:33 by pauldos-         ###   ########.fr       */
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
	}
	else
		std::cout << "No argument found!\n";
	return (0);
}
