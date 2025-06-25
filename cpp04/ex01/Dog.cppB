/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauldos- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 11:07:11 by pauldos-          #+#    #+#             */
/*   Updated: 2025/05/20 10:32:19 by pauldos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include <iostream>

Dog::Dog() : _brain(new Brain())
{
	this->type = "Dog";
	std::cout << "Dog constructor created!" << std::endl;
}

Dog::~Dog()
{
	delete _brain;
	std::cout << "Dog destroyed!" << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other), _brain(new Brain(*other._brain))
{
	type = other.type;
	std::cout << "Dog copy-constructor called!" << std::endl;
}

Dog& Dog::operator=(const Dog& other)
{
	std::cout << "Dog copy-assignment operator called!" << std::endl;
	if (this != &other)
	{
		Animal::operator=(other); // copy base part
		delete _brain;
		_brain = new Brain(*other._brain); // deep copy
		type  = other.type;
    }
	return *this;
}

void	Dog::makeSound() const
{
	std::cout << "woof woof" << std::endl;
}

void	Dog::setIdea(int index, const std::string& idea)
{
	_brain->setIdea(index, idea);
}

std::string Dog::getIdea(int index) const
{
	return _brain->getIdea(index);
}
