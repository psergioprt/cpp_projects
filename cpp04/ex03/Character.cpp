/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauldos- <pauldos-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 11:15:06 by pauldos-          #+#    #+#             */
/*   Updated: 2025/06/30 22:44:16 by pauldos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "AMateria.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"

#define RESET "\033[0m"
#define BGREEN "\033[92m"

Character::Character(std::string const & name) : _name(name), _indexFloor(-1)
{
	std::cout << BGREEN << "Character constructor called" << RESET << std::endl;
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
	for (int i = 0; i < 4; i++)
		this->_floor[i] = NULL; 
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
				this->_inventory[i] = other._inventory[i]->clone();
			else
				this->_inventory[i] = NULL;
		}
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
	for (int i = 0; i < 4; i++)
	{
		if (this->_floor[i])
			delete this->_floor[i];
	}
}

std::string const & Character::getName() const
{
	return this->_name;
}

void	Character::equip(AMateria* m)
{
	int	i;
	if (!m)
	{
		std::cerr << BGREEN << this->_name << " cannot equip NULL Materia" << RESET << std::endl;
		return;
	}
	for (i = 0; i < 4; i++)
	{
		if (!this->_inventory[i])
			break;
	}
	if (i == 4)
	{
		std::cout << BGREEN << this->_name << "'s inventory is full, cannot equip Materia" << RESET << std::endl;
		delete m;
		return;
	}
	this->_inventory[i] = m;
	std::cout << BGREEN << this->_name << " has equiped " << m->getType() << "in slot " << i << RESET << std::endl;
}

/*void Character::equip(AMateria* m) {
    if (!m) {
        std::cerr << "Cannot equip NULL Materia." << std::endl;
        return;
    }

    int i = 0;
    for (; i < 4; i++) {
        if (!this->_inventory[i])
            break;
    }

    if (i == 4) {
        std::cerr << this->_name << "'s inventory is full, cannot equip Materia." << std::endl;
        delete m;  // <-- prevent memory leak here by deleting passed pointer!
        return;
    }

    this->_inventory[i] = m;
    std::cout << this->_name << " has equipped " << m->getType() << " in slot " << i << std::endl;
}*/


void	Character::unequip(int idx)
{
	if (idx >= 0 && idx < 4 && this->_inventory[idx])
	{
		std::cout << BGREEN << this->_name << " unequips Materia from slot" << idx << RESET << std::endl;
		storeOnFloor(this->_inventory[idx]);
		this->_inventory[idx] = NULL;
	}
	else
		std::cout << BGREEN << "Cannot use materia: invalid slot or empty slot." << RESET << std::endl;
}

void	Character::use(int idx, ICharacter& target)
{
	if (idx >= 0 && idx < 4 && this->_inventory[idx])
		this->_inventory[idx]->use(target);
	else
		std::cout << BGREEN << "Cannot use materia: invalid slot or empty slot." << RESET << std::endl;
}

void	Character::storeOnFloor(AMateria * m)
{
	this->_indexFloor++;
	if (this->_indexFloor >= 4)
		this->_indexFloor = 0;
	if (this->_floor[this->_indexFloor])
	{
		delete this->_floor[this->_indexFloor];
		this->_floor[this->_indexFloor] = NULL;
	}
	this->_floor[this->_indexFloor] = m;
	std::cout << BGREEN << this->_name << " stores " << m->getType() << " on the floor at index [" << _indexFloor << "]" << std::endl;
}
