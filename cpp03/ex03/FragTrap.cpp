/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauldos- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 10:37:54 by pauldos-          #+#    #+#             */
/*   Updated: 2025/06/23 19:38:54 by pauldos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "FragTrap.hpp"

#define RESET "\033[0m"
#define CYAN "\033[96m"

FragTrap::FragTrap() : ClapTrap("default")
{
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
//	this->_maxHitPoints = 100; //Just added this to deal with top boundary of initialized hit points
	std::cout << "Default FragTrap has been created!" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
//	this->_maxHitPoints = 100; //Just added this to deal with top boundary of initialized hit points
	std::cout << CYAN << "FragTrap " << this->_name << " has been created with " << this->_hitPoints << " hit points, " << this->_energyPoints << " energy points and " << this->_attackDamage << " attack damage" << RESET << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << CYAN << "FragTrap " << this->_name << " has been destroyed!" << RESET << std::endl;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other)
{
	std::cout << CYAN << "FragTrap copy constructor called for " << other._name << "!" << RESET << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other)
{
	std::cout << CYAN << "FragTrap assignment operator called for " << other._name << "!" << RESET << std::endl;
	if (this != &other)
		ClapTrap::operator=(other);		
	return *this;
}

void	FragTrap::highFivesGuys()
{
	if (this->_hitPoints > 0)
		std::cout << CYAN << "FragTrap " << this->_name << " enthusiastically high fives you guys!" << RESET << std::endl;
	else
		std::cout << CYAN << "Even lying on the floor, FragTrap " << this->_name << " raises a hand to high five you guys!" << RESET << std::endl;
}

int	FragTrap::getDefaultHitPoints()
{
	return 100;
}

int	FragTrap::getDefaultAttackDamage()
{
	return 30;
}
