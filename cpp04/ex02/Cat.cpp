/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauldos- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 11:02:06 by pauldos-          #+#    #+#             */
/*   Updated: 2025/05/20 10:31:34 by pauldos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include <iostream>

Cat::Cat() : _brain(new Brain())
{
	this->type = "Cat";
	std::cout << "Cat constructor created!" << std::endl;
}

Cat::~Cat()
{
	delete _brain;
	std::cout << "Cat destroyed!" << std::endl;
}

Cat::Cat(const Cat& other): Animal(other), _brain(new Brain(*other._brain))
{
	type = other.type;
	std::cout << "Cat copy-constructor called!" << std::endl;
}

Cat& Cat::operator=(const Cat& other)
{
	std::cout << "Cat copy-assignment operator called!" << std::endl;
	if (this != &other)
	{
		Animal::operator=(other); // copy base part
		delete _brain;
		_brain = new Brain(*other._brain); // deep copy
		type  = other.type;
    }
	return *this;
}

void	Cat::makeSound() const
{
	std::cout << "miauuuuu" << std::endl;
}

void	Cat::setIdea(int index, const std::string& idea)
{
	_brain->setIdea(index, idea);
}

std::string Cat::getIdea(int index) const
{
	return _brain->getIdea(index);
}
