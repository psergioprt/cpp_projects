/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauldos- <pauldos-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 14:25:55 by pauldos-          #+#    #+#             */
/*   Updated: 2025/05/12 15:12:22 by pauldos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap clap("Xico");

	clap.attack("enemy");
	clap.takeDamage(3);
	clap.beRepaired(2);
	clap.attack("enemy");
	clap.takeDamage(4);
	clap.beRepaired(1);
	clap.attack("enemy");
	clap.takeDamage(10);
	return 0;
}
