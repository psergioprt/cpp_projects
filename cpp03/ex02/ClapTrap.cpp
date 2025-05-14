/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauldos- <pauldos-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 12:20:26 by pauldos-          #+#    #+#             */
/*   Updated: 2025/05/14 13:43:22 by pauldos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "Creating name " << this->_name << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other)
{
	this->_name = other._name;
	this->_hitPoints = other._hitPoints;
	this->_energyPoints = other._energyPoints;
	this->_attackDamage = other._attackDamage;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
	if (this != &other)
	{
		this->_name = other._name;
		this->_hitPoints = other._hitPoints;
		this->_energyPoints = other._energyPoints;
		this->_attackDamage = other._attackDamage;
	}
	return *this;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << this->_name << " destructor called!"<<std::endl;
}

void	ClapTrap::attack(const std::string& target)
{
	if (_hitPoints <= 0 || _energyPoints <= 0)
	{
		std::cout << "ClapTrap " << this->_name << " cannot attack" << std::endl;
		return;
	}
	_energyPoints--;
	std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (_hitPoints == 0)
	{
		std::cout << "ClapTrap " << _name << " can't take further damage!" << std::endl;
		return;
	}
	if (amount >= _hitPoints)
		_hitPoints = 0;
	else
		_hitPoints -= amount;
	std::cout << "ClapTrap " << _name << " takes " << amount << " damage, current HP " << _hitPoints << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (_hitPoints == 100)
	{
		std::cout << "ClapTrap " << _name << " can't be more repaired!" << std::endl;
		return;
	}
	if (_energyPoints <= 0)
	{
		std::cout << "ClapTrap " << _name << " has no energy left to repair!" << std::endl;
		return;
	}
	if (_hitPoints + amount > 100)
		_hitPoints = 100;
	else
		_hitPoints += amount;
	_energyPoints--;
	std::cout << "ClapTrap " << _name << " has recovered to " << _hitPoints << " and has " << _energyPoints << " energy left!" << std::endl;
}
