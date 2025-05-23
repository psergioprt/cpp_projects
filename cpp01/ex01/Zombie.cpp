/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauldos- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 10:27:07 by pauldos-          #+#    #+#             */
/*   Updated: 2025/05/23 20:01:40 by pauldos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie()
{
	std::cout << "Unnamed Zombie created!" << std::endl;
}
Zombie::Zombie(std::string name) : _name(name)
{
	std::cout << "Zombie named " << this->_name << " has been created!" << std::endl;
}

Zombie::~Zombie()
{
	std::cout << "Zombie named " << this->_name << " has been destroyed!" << std::endl;
}

std::string	Zombie::get_name()const
{
	return (this->_name);
}

void		Zombie::set_name(const std::string &str)
{
	this->_name = str;

}

void		Zombie::announce() const
{
	std::cout << this->_name << " BraiiiiiiinnnzzzZ..." << std::endl;
}
