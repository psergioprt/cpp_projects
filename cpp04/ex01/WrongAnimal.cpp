/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauldos- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 11:13:53 by pauldos-          #+#    #+#             */
/*   Updated: 2025/06/24 15:54:38 by pauldos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "WrongAnimal.hpp"

#define RESET "\033[0m"
#define WHITE "\033[37m"

WrongAnimal::WrongAnimal() : type("wrongAnimal")
{
	std::cout << WHITE << "wrongAnimal constructor created!" << RESET << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other) : type(other.type)
{
	std::cout << WHITE << "wrongAnimal copy constructor" << RESET << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other)
{
	if (this != &other)
		this->type = other.type;
	std::cout << WHITE << "wrongAnimal assignment operator" << RESET << std::endl;
	return *this;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << WHITE << "wrongAnimal destroyed!" << RESET << std::endl;
}

std::string WrongAnimal::getType() const
{
	return this->type;
}

void	WrongAnimal::makeSound() const
{
	std::cout << WHITE << "* generic animal sound *" << RESET << std::endl;
}
