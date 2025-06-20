/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauldos- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 10:34:41 by pauldos-          #+#    #+#             */
/*   Updated: 2025/06/20 16:31:29 by pauldos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"

int	main(void)
{
	std::cout << "Clap constructor created" << std::endl;
	ClapTrap clap("Jeff");
	std::cout << "---------------------------" << std::endl;
	std::cout << std::endl;
	
	std::cout << "first attack" << std::endl;
	clap.attack("Fred");
	clap.takeDamage(3);
	clap.beRepaired(2);
	
	std::cout << "---------------------------" << std::endl;
	std::cout << std::endl;

	std::cout << "second attack" << std::endl;
	clap.attack("John");
	clap.takeDamage(4);
	clap.beRepaired(1);
	std::cout << std::endl;
	std::cout << "---------------------------" << std::endl;
	
	std::cout << "third attack" << std::endl;
	clap.attack("Lewis");
	clap.takeDamage(10);
	clap.beRepaired(2);
	std::cout << "---------------------------" << std::endl;

	std::cout << "Testing copy constructor\n";
	ClapTrap cpCopy(clap);
	std::cout << std::endl;
	std::cout << "Testing assignment operator\n";
	ClapTrap cpAssigned("Temp");
	cpAssigned = clap;
	std::cout << std::endl;
	
	return 0;
}
