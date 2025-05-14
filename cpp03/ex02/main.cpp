/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauldos- <pauldos-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 13:20:11 by pauldos-          #+#    #+#             */
/*   Updated: 2025/05/14 13:41:07 by pauldos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "FragTrap.hpp"

int	main()
{
	std::cout << "Creating FragTrap named Einstein\n";
	FragTrap frag("Einstein");

	std::cout << "\nTesting attack, damage, repair:\n";
	frag.attack("Bohr");
	frag.takeDamage(40);
	frag.beRepaired(30);

	std::cout << "\nTesting high five:\n";
	frag.highFivesGuys();

	std::cout << "\nTesting copy constructor:\n";
	FragTrap fragCopy(frag);

	std::cout << "\nTesting assignment operator:\n";
	FragTrap fragAssigned("Temp");
	fragAssigned = frag;
	
	std::cout << "\nDestruction will happen in reverse order of creation.\n";
	return 0;
}

