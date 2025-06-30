/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauldos- <pauldos-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 11:15:06 by pauldos-          #+#    #+#             */
/*   Updated: 2025/06/30 12:28:29 by pauldos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "AMateria.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"

#define RESET "\033[0m"
#define BGREEN "\033[92m"

Character::Character(std::string const & name) : _name(name)
{
	std::cout << BGREEN << "Character constructor called" << RESET << std::endl;
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
}

Character::Character(const Character& other) : _name(other._name)
{
	std::cout << BGREEN << "Character copy constructor called" << RESET << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (other._inventory[i])
			this->_inventory[i] = other._inventory[i]->clone();
		else
			this->_inventory[i] = NULL;
	}

}

Character& Character::operator=(const Character& other)
{
	std::cout << BGREEN << "Character copy assignment operator" << RESET << std::endl;
	if (this != &other)
	{
		this->_name = other._name;
		for (int i = 0; i < 4; i++)
		{
			if (this->_inventory[i])
				delete this->_inventory[i];
			if (other._inventory[i])
				this->_inventory[i] = other->_inventory[i]->clone();
			else
				this->_inventory[i] = NULL;
		}
	return *this;
}

Character::~Character()
{
	std::cout << BGREEN << "Character destructor called" << RESET << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (this->_inventory[i])
			delete this->_inventory[i];
	}
}

std::string consti & Character::getName() const
{
	return this->_name;
}

void	Character::equip(AMateria* m)
{
	for (int i = 0; i < 4; i++)
	{
		if (!this->_inventory[i])
		{
			this->_inventory[i] = m;
			std::cout << BGREEN << this->_name << " equips Materia in slot " << i << RESET << std::endl;
			return;
		}
	}
	std::cout << BGREEN << this->_name << "'s inventory is full, cannot equip." << RESET << std::endl;
}

void	Character::unequip(int idx)
{
	if (idx >= 0 && idx < 4 && this->_inventory[idx])
	{
		std::cout << BGREEN << this->_name << " unequips Materia from slot" << idx << RESET << std::endl;
		this->_inventory[idx] = NULL;
	}
}

void	Character::use(int idx, ICharacter& target)
{
	if (idx >= 0 && idx < 4 && this->_inventory[idx])
		this->_inventory[idx]->use(target);
}
