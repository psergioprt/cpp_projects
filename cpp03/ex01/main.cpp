/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauldos- <pauldos-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 15:56:36 by pauldos-          #+#    #+#             */
/*   Updated: 2025/05/13 16:16:35 by pauldos-         ###   ########.fr       */
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

	return 0;
}
