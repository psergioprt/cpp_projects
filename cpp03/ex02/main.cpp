/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauldos- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 10:38:36 by pauldos-          #+#    #+#             */
/*   Updated: 2025/06/23 15:43:49 by pauldos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

#define RESET	"\033[0m"
#define YELLOW	"\033[93m"

int	main()
{
	std::cout << YELLOW << "CALLING CONSTRUCTORS" << RESET << std::endl;
	ClapTrap	ct("Edison");
	ScavTrap	st("Newton");
	ScavTrap	st2("Tesla");
	ScavTrap	st3("daVinci");
	FragTrap	ft1("Einstein");
	FragTrap	ft2("Gutenberg");
	std::cout << std::endl;
	
	std::cout << YELLOW << "ATTACK 1 - CLAPTRAP" << RESET << std::endl;
	ct.attack("Thomas");
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

	/*std::cout << YELLOW << "ATTACK 4 - SCAVTRAP" << RESET << std::endl;
	st3.takeDamage(55);
	for (int i = 0; i < 55; i++)
		st3.beRepaired(1);
	st3.takeDamage(100);
	st3.takeDamage(1);
	st3.guardGate();
	std::cout << std::endl;*/

	std::cout << YELLOW << "ATTACK 5 - FRAGTRAP" << RESET << std::endl;
	ft1.attack("Albert");
	ft1.takeDamage(10);
	ft1.takeDamage(40);
	ft1.highFivesGuys();
	ft1.takeDamage(51);
	ft1.highFivesGuys();
	ft1.beRepaired(30);
	ft1.beRepaired(50);
	ft1.beRepaired(30);
	ft1.beRepaired(1);
	std::cout << std::endl;

	std::cout << YELLOW << "ATTACK 6 - FRAGTRAP" << RESET << std::endl;
	for (int i = 0; i < 105; i++)
		ft2.takeDamage(1);
	std::cout << std::endl;

	/*std::cout << YELLOW << "TESTING COPY AND OPERATOR" << RESET << std::endl;
	FragTrap	fragCopy(ft1);
	FragTrap	fragAssign("Temp");
	fragAssign = ft1;
	std::cout << std::endl;*/
	
	std::cout << YELLOW << "DESTRUCTION WILL HAPPEN IN REVERSE ORDER OF CREATION" << RESET << std::endl;
	return 0;
}
