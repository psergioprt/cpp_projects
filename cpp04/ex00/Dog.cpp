/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauldos- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 11:13:27 by pauldos-          #+#    #+#             */
/*   Updated: 2025/06/24 14:01:06 by pauldos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include <iostream>

#define RESET "\033[0m"
#define GREEN "\033[93m"

Dog::Dog()
{
	this->type = "Dog";
	std::cout << GREEN << "Dog default constructor created" << RESET << std::endl;
}

Dog::Dog(const Dog &other) : Animal()
{
	this->type = other.type;
	std::cout << GREEN << "Dog copy constructor" << RESET << std::endl;
}

Dog& Dog::operator=(const Dog& other)
{
	if (this != &other)
		this->type = other.type;
	std::cout << GREEN << "Dog assignement operator" << RESET << std::endl;
	return *this;
}

Dog::~Dog()
{
	std::cout << GREEN << "Dog destructor called" << RESET << std::endl;
}

void	Dog::makeSound() const
{
	std::cout << GREEN << "WOOF" << RESET << std::endl;
}
