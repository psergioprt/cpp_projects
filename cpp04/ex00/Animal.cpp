/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauldos- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 11:12:46 by pauldos-          #+#    #+#             */
/*   Updated: 2025/06/25 07:12:26 by pauldos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Animal.hpp"

#define RESET "\033[0m"
#define BLUE "\033[34m"

Animal::Animal() : type("Animal")
{
	std::cout << BLUE << "Animal default constructor created!" << RESET << std::endl;
}

Animal::Animal(const Animal &other) : type(other.type)
{
	std::cout << BLUE << "Animal copy constructor called" << RESET << std::endl;
}

Animal& Animal::operator=(const Animal &other)
{
	if (this != &other)
		this->type = other.type;
	std::cout << BLUE << "Animal assignment operator called" << RESET << std::endl;
	return *this;
}

Animal::~Animal()
{
	std::cout << BLUE << "Animal destroyed!" << RESET << std::endl;
}

std::string	Animal::getType() const
{
	return this->type;
}

void	Animal::makeSound() const
{
	std::cout << BLUE << "* generic animal sound *" << RESET << std::endl;
}
