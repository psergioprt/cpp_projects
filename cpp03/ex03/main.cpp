/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauldos- <pauldos-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 11:16:14 by pauldos-          #+#    #+#             */
/*   Updated: 2025/05/15 11:52:23 by pauldos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "DiamondTrap.hpp"

int	main()
{
	DiamondTrap dt("DaVinci");
	
	dt.attack("Leonardo");
	dt.takeDamage(5);
	dt.beRepaired(10);

	std::cout << "Testing whoAmI\n";
	dt.whoAmI();

	std::cout << "Testing copy constructor\n";
	DiamondTrap dtCopy(dt);

	std::cout << "Testing assignment operator\n";
	DiamondTrap dtAssigned("Temp");
	dtAssigned = dt;

	std::cout << "Destruction will happen in reverse order.\n";
	return 0;	
}
