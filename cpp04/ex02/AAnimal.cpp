/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauldos- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 11:12:46 by pauldos-          #+#    #+#             */
/*   Updated: 2025/06/29 01:20:23 by pauldos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "AAnimal.hpp"

#define RESET "\033[0m"
#define BLUE "\033[34m"

AAnimal::AAnimal() : _type("Animal")
{
	std::cout << BLUE << "Animal default constructor created!" << RESET << std::endl;
}

AAnimal::AAnimal(const AAnimal &other) : _type(other._type)
{
	std::cout << BLUE << "Animal copy constructor called" << RESET << std::endl;
}

AAnimal& AAnimal::operator=(const AAnimal &other)
{
	if (this != &other)
		this->_type = other._type;
	std::cout << BLUE << "Animal assignment operator called" << RESET << std::endl;
	return *this;
}

AAnimal::~AAnimal()
{
	std::cout << BLUE << "Animal destroyed!" << RESET << std::endl;
}

std::string	AAnimal::getType() const
{
	return this->_type;
}

// Commented it out as makeSound() was set as pure virtual at .hpp file, so AAnimal class becomes abstract
/*void	AAnimal::makeSound() const
{
	std::cout << BLUE << "* generic animal sound *" << RESET << std::endl;
}*/
