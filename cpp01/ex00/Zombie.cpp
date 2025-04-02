/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauldos- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 10:54:15 by pauldos-          #+#    #+#             */
/*   Updated: 2025/04/02 15:58:35 by pauldos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(void)
{
	std::cout << "Zombi object named " << this->_name << "has been created!" << std::endl;
}

Zombie::~Zombie(void)
{
	std::cout << "...is destroid!" << std::endl;
}

std::string	Zombie::get_name(void) const
{
	return (this->_name);
}

void	Zombie::announce(void) const
{
	std::cout << get_name() << " BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::set_name(const std::string &str)
{
	this->_name = str;
}
