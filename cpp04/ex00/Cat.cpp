/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauldos- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 11:13:07 by pauldos-          #+#    #+#             */
/*   Updated: 2025/06/27 21:28:57 by pauldos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Cat.hpp"

#define RESET "\033[0m"
#define CYAN "\033[96m"

Cat::Cat()
{
	this->_type = "Cat";
	std::cout << CYAN << "Cat default construtor created" << RESET << std::endl;
}

Cat::Cat(const Cat &other) : Animal()
{
	this->_type = other._type;
	std::cout << CYAN << "Cat copy constructor" << RESET << std::endl;
}

Cat& Cat::operator=(const Cat &other)
{
	if (this != &other)
		this->_type = other._type;
	std::cout << CYAN << "Cat assignement operator" << RESET << std::endl;
	return *this;
}

Cat::~Cat()
{
	std::cout << CYAN << "Cat destructor called" << RESET << std::endl;
}

void Cat::makeSound() const
{
	std::cout << CYAN << "Meowww" << RESET << std::endl;
}
