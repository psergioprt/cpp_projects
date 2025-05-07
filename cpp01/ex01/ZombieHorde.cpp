/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauldos- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 11:20:47 by pauldos-          #+#    #+#             */
/*   Updated: 2025/05/07 12:09:27 by pauldos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie*	zombieHorde(int N, std::string name)
{
	Zombie*	horde;
	int	i;

	horde = new Zombie[N];
	i = 0;

	if (N <= 0)
		return (NULL);
	while (i < N)
	{
		horde[i].set_name(name);
		i++;
	}
	return (horde);
}
