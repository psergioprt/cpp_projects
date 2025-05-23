/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauldos- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 10:54:15 by pauldos-          #+#    #+#             */
/*   Updated: 2025/05/23 11:20:17 by pauldos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie(std::string name)// : _name(name)
{
	this->_name = name;
	std::cout << "Zombi object named " << this->_name << " has been created!" << std::endl;
}

Zombie::~Zombie(void)
{
	std::cout << "Zombi " << this->_name << " is destroid!" << std::endl;
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
