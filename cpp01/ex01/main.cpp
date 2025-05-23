/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauldos- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 10:31:18 by pauldos-          #+#    #+#             */
/*   Updated: 2025/05/23 20:37:51 by pauldos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name);

int	main()
{
	int	count;
	int	i;
	Zombie*	horde;

	count = 5;
	i = 0;
	horde = zombieHorde(count, "Walker");
	while (i < count)
	{
		horde[i].announce();
		i++;
	}
	delete [] horde;
	return 0;
}
