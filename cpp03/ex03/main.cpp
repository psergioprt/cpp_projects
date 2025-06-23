/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauldos- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 10:59:19 by pauldos-          #+#    #+#             */
/*   Updated: 2025/06/23 19:23:17 by pauldos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "DiamondTrap.hpp"

#define RESET "\033[0m"
#define YELLOW "\033[93m"

int	main()
{
	std::cout << YELLOW << "CALLING CONSTRUCTORS" << RESET << std::endl;
	DiamondTrap dt("Bell");
	DiamondTrap dt1("Morse");
	std::cout << std::endl;

	std::cout << YELLOW << "DIAMONDTRAP VALUES HELPER" << RESET << std::endl;
	std::cout << "Hit points (FragTrap): 100" << std::endl;
	std::cout << "Energy points (ScavTrap): 50" << std::endl;
	std::cout << "Attack damage (FragTrap): 30" << std::endl;
	std::cout << "attack (ScavTrap)" << std::endl;
	std::cout << std::endl;
	
	std::cout << YELLOW << "ATTACK 1 - DIAMONDTRAP" << RESET << std::endl;
	dt.attack("Alexander");
	dt.takeDamage(30);
	dt.takeDamage(60);
	dt.takeDamage(10);
	dt.takeDamage(1);
	dt.beRepaired(10);
	dt.beRepaired(30);
	dt.whoAmI();
	dt.beRepaired(62);
	dt.beRepaired(1);
	std::cout << std::endl;

	std::cout << YELLOW << "ATTACK 2 - DIAMONDTRAP" << RESET << std::endl;
	dt1.attack("Samuel");
	for (int i = 0; i < 55; i++)
		dt.attack("Alexander");
	std::cout << std::endl;

	std::cout << YELLOW << "Testing copy constructor" << RESET << std::endl;
	DiamondTrap dtCopy(dt);

	std::cout << YELLOW << "Testing assignment operator" << RESET << std::endl;
	DiamondTrap dtAssigned("Temp");
	dtAssigned = dt;
	std::cout << std::endl;

	std::cout << YELLOW << "Destruction will happen in reverse order!" << RESET << std::endl;
	return 0;	
}
