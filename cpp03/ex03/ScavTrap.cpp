/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauldos- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 10:35:58 by pauldos-          #+#    #+#             */
/*   Updated: 2025/06/23 19:28:05 by pauldos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ScavTrap.hpp"

#define RESET   "\033[0m"
#define BLUE    "\033[34m"

ScavTrap::ScavTrap() : ClapTrap("default")
{
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
//	this->_maxHitPoints = 100; //just added this for better dealing with top boundaries!
	std::cout << "Default ScavTrap created" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
//	this->_maxHitPoints = 100; //just added this for better dealing with top boundaries!
	std::cout << BLUE << "ScavTrap " << this->_name << " has been created with " << this->_hitPoints << " hit Points, " << this->_energyPoints << " energy points and " << this->_attackDamage << " attack damage" << RESET << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << BLUE << "ScavTrap " << this->_name << " has been destroyed!" << RESET << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other)
{
	std::cout << BLUE << "ScavTrap copy constructor called for " << other._name << "!" << RESET << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
	std::cout << BLUE << "ScavTrap assignment operator called for " << other._name << "!" << RESET << std::endl;
	if (this != &other)
		ClapTrap::operator=(other);
	return *this;
}

void	ScavTrap::attack(const std::string& target)
{
	if (this->_hitPoints == 0)
	{
		std::cout << BLUE << "ScavTrap " << this->_name << " can't attack because it's out of hit points! Current hit points: " << this->_hitPoints  << RESET << std::endl;
		return;
	}
	if (this->_energyPoints == 0)
	{
		std::cout << BLUE << "ScavTrap " << this->_name << " is out of energy points so can't attack! Current energy points: " << this->_energyPoints << RESET << std::endl;
		return;
	}
	this->_energyPoints--;
	std::cout << BLUE << "ScavTrap " << this->_name << " fiercely attacks " << target << ", causing " << this->_attackDamage << " attack damage! (Energy left: " << this->_energyPoints << ")" << RESET << std::endl;
}

void	ScavTrap::guardGate()
{
	std::cout << BLUE << "ScavTrap " << this->_name << " is now in the Gate keeper mode!" << RESET << std::endl;
}

int	ScavTrap::getDefaultEnergyPoints()
{
	return 50;
}
