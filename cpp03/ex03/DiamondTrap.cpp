/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauldos- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 10:58:11 by pauldos-          #+#    #+#             */
/*   Updated: 2025/06/23 12:24:34 by pauldos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "DiamondTrap.hpp"

#define RESET "\033[0m"
#define MAGENTA "\033[95m"

DiamondTrap::DiamondTrap() : ClapTrap("default_clap_name"), ScavTrap(), FragTrap(), _name("default")
{
	this->_hitPoints = FragTrap::getDefaultHitPoints();
	this->_energyPoints = ScavTrap::getDefaultEnergyPoints();
	this->_attackDamage = FragTrap::getDefaultAttackDamage();
//      this->_maxHitPoints = FragTrap::_maxHitPoints; //Just added this to deal with top boundary of initialized hit points
	std::cout << MAGENTA << "Default DiamondTrap has been created!" << RESET << std::endl;
}

DiamondTrap::DiamondTrap(const std::string name) : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name), _name(name)
{
	ClapTrap::_hitPoints = FragTrap::getDefaultHitPoints();
	ClapTrap::_energyPoints = ScavTrap::getDefaultEnergyPoints();
	ClapTrap::_attackDamage = FragTrap::getDefaultAttackDamage();
//      this->_maxHitPoints = FragTrap::_maxHitPoints; //Just added this to deal with top boundary of initialized hit points
	std::cout << MAGENTA << "DiamondTrap " << this->_name << " has been created with " << this->_hitPoints << " hit points, " << this->_energyPoints << " energy points and " << this->_attackDamage << " attack damage" << RESET << std::endl;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << MAGENTA << "DiamondTrap " << _name << " has been destroyed!" << RESET << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other) : ClapTrap(other), ScavTrap(other), FragTrap(other), _name(other._name)
{
	std::cout << MAGENTA << "DiamondTrap copy constructor called for " << other._name << "!" << RESET << std::endl;
	this->_hitPoints = other._hitPoints;
	this->_energyPoints = other._energyPoints;
	this->_attackDamage = other._attackDamage;
//	this->_maxHitPoints = other._maxHitPoints;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other)
{
	std::cout << MAGENTA << "DiamondTrap assignment operator called for " << other._name << "!" << RESET << std::endl;
	if (this != &other)
	{
		this->_name = other._name;
		this->_hitPoints = other._hitPoints;
		this->_energyPoints = other._energyPoints;
		this->_attackDamage = other._attackDamage;
//		this->_maxHitPoints = other._maxHitPoints;
	}
	return *this;
}

void	DiamondTrap::whoAmI()
{
	std::cout << MAGENTA << "I am DiamondTrap \"" << this->_name << "\" and my ClapTrap name is \"" << this->ClapTrap::_name << "\"" << RESET << std::endl;
}
