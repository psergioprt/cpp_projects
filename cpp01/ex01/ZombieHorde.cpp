/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauldos- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 11:20:47 by pauldos-          #+#    #+#             */
/*   Updated: 2025/05/23 20:53:37 by pauldos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <sstream>

Zombie*	zombieHorde(int N, std::string name)
{
	Zombie*	horde;
	int	i;

	i = 0;
	if (N <= 0)
		return NULL;
	horde = new Zombie[N];
	while (i < N)
	{
		std::ostringstream num;
		num << i;
		std::string numberedName = name + num.str();
		horde[i].set_name(numberedName);
		i++;
	}
	return horde;
}
