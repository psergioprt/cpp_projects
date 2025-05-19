/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauldos- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 10:34:41 by pauldos-          #+#    #+#             */
/*   Updated: 2025/05/19 10:34:45 by pauldos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap clap("Jeff");

	clap.attack("enemy");
	clap.takeDamage(3);
	clap.beRepaired(2);

	clap.attack("John");
	clap.takeDamage(4);
	clap.beRepaired(1);
	
	clap.attack("enemy");
	clap.beRepaired(2);
	clap.takeDamage(10);

	std::cout << "Testing copy constructor\n";
	ClapTrap cpCopy(clap);

	std::cout << "Testing assignment operator\n";
	ClapTrap cpAssigned("Temp");
	cpAssigned = clap;

	std::cout << "Destruction will happen in reverse order.\n";
	return 0;
}
