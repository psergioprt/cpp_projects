/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauldos- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 11:13:07 by pauldos-          #+#    #+#             */
/*   Updated: 2025/06/27 21:47:38 by pauldos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Cat.hpp"

#define RESET "\033[0m"
#define CYAN "\033[96m"

Cat::Cat() : Animal()
{
	this->_type = "Cat";
	this->_brain = new Brain;
	std::cout << CYAN << "Cat default constructor created" << RESET << std::endl;
}

Cat::Cat(const Cat &other) : Animal(other)
{
	this->_type = other._type;
	this->_brain = new Brain(*other._brain);
	std::cout << CYAN << "Cat copy constructor" << RESET << std::endl;
}

Cat& Cat::operator=(const Cat &other)
{
	if (this != &other)
	{
		this->_type = other._type;
		*this->_brain = *other._brain;
	}
	std::cout << CYAN << "Cat assignment operator" << RESET << std::endl;
	return *this;
}

Cat::~Cat()
{
	delete this->_brain;
	std::cout << CYAN << "Cat destructor called" << RESET << std::endl;
}

void Cat::makeSound() const
{
	std::cout << CYAN << "Meowww" << RESET << std::endl;
}

void	Cat::setIdea(int index, const std::string& idea)
{
	if (this->_brain)
		this->_brain->setIdea(index, idea);
}

std::string	Cat::getIdea(int index) const
{
	if (this->_brain)
		return this->_brain->getIdea(index);
	return "";
}
