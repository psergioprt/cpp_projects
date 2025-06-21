/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauldos- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 10:36:23 by pauldos-          #+#    #+#             */
/*   Updated: 2025/06/21 10:11:10 by pauldos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ScavTrap.hpp"

#define RESET	"\033[0m"
#define YELLOW	"\033[93m"


int	main()
{
	std::cout << YELLOW << "CALLING CONSTRUCTORS" << RESET << std::endl;
	ClapTrap	ct("Edison");
	ScavTrap	st("Newton");
	ScavTrap	st2("Tesla");
	std::cout << std::endl;
	
	std::cout << YELLOW << "ATTACK 1 - CLAPTRAP" << RESET << std::endl;
	ct.attack("Tomas");
	ct.takeDamage(5);
	ct.takeDamage(2);
	ct.takeDamage(5);
	ct.beRepaired(3);
	ct.beRepaired(5);
	ct.beRepaired(4);
	std::cout << std::endl;
	
	std::cout << YELLOW << "ATTACK 2 - SCAVTRAP" << RESET << std::endl;
	st.attack("Isaac");
	st.takeDamage(10);
	st.takeDamage(15);
	st.attack("Isaac");
	st.takeDamage(20);
	st.beRepaired(15);
	st.attack("Isaac");
	st.beRepaired(25);
	st.beRepaired(20);
	st.guardGate();
	std::cout << std::endl;

	std::cout << YELLOW << "ATTACK 3 - SCAVTRAP" << RESET << std::endl;
	st2.attack("Elon");
	st2.takeDamage(20);
	st2.takeDamage(25);
	st2.attack("Elon");
	st2.takeDamage(80);
	st2.beRepaired(25);
	st2.attack("Elon");
	st2.beRepaired(25);
	st2.beRepaired(90);
	st2.guardGate();
	std::cout << std::endl;
	
	std::cout << YELLOW << "TESTING COPY CONSTRUCTOR" << RESET << std::endl;
	ScavTrap stCopy(st);
	ScavTrap st2Copy(st2);
	std::cout << std::endl;

	std::cout << YELLOW << "TESTING COPY ASSIGNMENT OPERATOR" << RESET << std::endl;
	ScavTrap stAssign("Temp");
	stAssign = st;
	ScavTrap st2Assign("Temp2");
	st2Assign = st2;
	std::cout << std::endl;
	
	std::cout << YELLOW << "DESTRUCTION WILL HAPPEN IN REVERSE ORDER OF CREATION" << RESET << std::endl;
	return 0;
}
