/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauldos- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 10:35:24 by pauldos-          #+#    #+#             */
/*   Updated: 2025/06/23 19:25:55 by pauldos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("default"), _hitPoints(), _energyPoints(), _attackDamage()
{
	std::cout << "Default ClapTrap created!" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
//	this->_maxHitPoints = 10; //added this just for better dealing with top boundaries
	std::cout << "ClapTrap " << this->_name << " has been created with " << this->_hitPoints << " hit points " << this->_energyPoints << " energy points and " << this->_attackDamage << " attack damage!" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other)
{
	this->_name = other._name;
	this->_hitPoints = other._hitPoints;
	this->_energyPoints = other._energyPoints;
	this->_attackDamage = other._attackDamage;
	std::cout << "ClapTrap copy constructor called for " << this->_name << "!" << std::endl;
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
	std::cout << "ClapTrap assignment operator called for " << this->_name << "!" << std::endl;
	return *this;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << this->_name << " destructor called!" << std::endl;
}

void	ClapTrap::attack(const std::string& target)
{
	if (this->_hitPoints <= 0 || this->_energyPoints <= 0)
	{
		std::cout << "ClapTrap " << this->_name << " cannot attack" << std::endl;
		return;
	}
	this->_energyPoints--;
	std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!" << " Hit points: " << this->_hitPoints << " | Energy points: " << this->_energyPoints << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hitPoints == 0)
	{
		std::cout << "ClapTrap " << this->_name << " can't take further damage!" << " Hit points: " << this->_hitPoints << " | Energy Points: " << this->_energyPoints << std::endl;
		return;
	}
	if (amount >= this->_hitPoints)
		this->_hitPoints = 0;
	else
		this->_hitPoints -= amount;
	std::cout << "ClapTrap " << this->_name << " takes " << amount << " damage. Hit points: " << this->_hitPoints << " | Energy points: " << this->_energyPoints << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_energyPoints == 0)
	{
		std::cout << "ClapTrap " << this->_name << " has no energy left to repair!" << " Hit points: " << this->_hitPoints << " Energy Points: " << this->_energyPoints << std::endl;
		return;
	}
	this->_hitPoints += amount;
	this->_energyPoints--;
	std::cout << "ClapTrap " << this->_name << " recovers " << amount << ". Hit points: " << this->_hitPoints << " | Energy points: " << this->_energyPoints << std::endl;
}

// This beRepaired function is meant to deal with max hit points, to don't increase more than the initial value.
// I've commented it because I was not sure if I could deal with it, as the subject does not say anything about it.
/*void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_hitPoints == this->_maxHitPoints)
	{
		std::cout << "ClapTrap " << this->_name << " can't be more repaired because can't have more than " << this->_hitPoints << std::endl;
		return;
	}
	if (this->_energyPoints <= 0)
	{
		std::cout << "ClapTrap " << this->_name << " has no energy left to repair!" << "Hit points: " << this->_hitPoints << " Energy Points: " << this->_energyPoints << std::endl;
		return;
	}
	if (this->_hitPoints + amount > this->_maxHitPoints)
		this->_hitPoints = this->_maxHitPoints;
	else
		this->_hitPoints += amount;
	this->_energyPoints--;
	std::cout << "ClapTrap " << this->_name << " recovers " << amount << ". Hit points: " << this->_hitPoints << " | Energy points: " << this->_energyPoints << std::endl;
}*/
