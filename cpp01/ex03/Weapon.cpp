/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauldos- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 10:54:16 by pauldos-          #+#    #+#             */
/*   Updated: 2025/05/23 21:25:50 by pauldos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include <iostream>

Weapon::Weapon(std::string type) : _type(type)
{
	std::cout << "Weapon object named \"" << this->_type << "\" has been created!" << std::endl;
}

Weapon::~Weapon()
{
	std::cout << "Weapon object named \"" << this->_type << "\" has been destroyed" << std::endl;
}

const	std::string&	Weapon::getType() const
{
	return (this->_type);
}

void	Weapon::setType(const std::string& type)
{
	this->_type = type;
}
