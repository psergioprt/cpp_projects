/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauldos- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 11:13:27 by pauldos-          #+#    #+#             */
/*   Updated: 2025/06/29 01:05:52 by pauldos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include <iostream>

#define RESET "\033[0m"
#define GREEN "\033[93m"

Dog::Dog() : AAnimal()
{
	this->_type = "Dog";
	this->_brain = new Brain;
	std::cout << GREEN << "Dog default constructor created" << RESET << std::endl;
}

Dog::Dog(const Dog &other) : AAnimal(other)
{
	this->_type = other._type;
	this->_brain = new Brain(*other._brain);
	std::cout << GREEN << "Dog copy constructor" << RESET << std::endl;
}

Dog& Dog::operator=(const Dog& other)
{
	std::cout << GREEN << "Dog assignment operator" << RESET << std::endl;
	if (this != &other)
	{
		AAnimal::operator=(other);
		delete this->_brain;
		this->_brain = new Brain(*other._brain);
	}
	return *this;
}

Dog::~Dog()
{
	delete this->_brain;
	std::cout << GREEN << "Dog destructor called" << RESET << std::endl;
}

void	Dog::makeSound() const
{
	std::cout << GREEN << "WOOF" << RESET << std::endl;
}

void	Dog::setIdea(int index, const std::string& idea)
{
	if (this->_brain)
		this->_brain->setIdea(index, idea);
}

std::string	Dog::getIdea(int index) const
{
	if (this->_brain)
		return this->_brain->getIdea(index);
	return "";
}
