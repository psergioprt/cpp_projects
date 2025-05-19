/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauldos- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 10:36:23 by pauldos-          #+#    #+#             */
/*   Updated: 2025/05/19 10:36:28 by pauldos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ScavTrap.hpp"

int	main()
{
	ScavTrap	st("Newton");
	ScavTrap	st2("Tesla");

	st.attack("Isaac");
	st.takeDamage(30);
	st.beRepaired(20);
	st.guardGate();

	st2.attack("Elon");
	st2.takeDamage(20);
	st2.beRepaired(10);
	st2.guardGate();

	std::cout << "Testing copy constructor\n";
	ScavTrap stCopy(st);
	ScavTrap st2Copy(st2);

	std::cout << "Testing assignment operator\n";
	ScavTrap stAssign("Temp");
	stAssign = st;
	ScavTrap st2Assign("Temp2");
	st2Assign = st2;

	std::cout << "Destruction will happen in reverse order of creation.\n";
	return 0;
}
