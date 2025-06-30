/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauldos- <pauldos-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 13:18:26 by pauldos-          #+#    #+#             */
/*   Updated: 2025/06/30 15:07:13 by pauldos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "MateriaSource.hpp"
#include "AMateria.hpp"

#define RESET "\033[0m"
#define CYAN "\033[0m"

MateriaSource::MateriaSource()
{
	std::cout << CYAN << "MateriaSource default constructor called" << RESET << std::endl;
	for (int i = 0; i < 4; i++)
		this->_storage[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource& other)
{
	std::cout << CYAN << "MateriaSource copy constructor called" << RESET << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (other._storage[i])
			this->_storage[i] = other._storage[i]->clone();
		else
			this->_storage[i] = NULL;
	}
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other)
{
	std::cout << CYAN << "MateriaSource copy assignment operator" << RESET << std::endl;
	if (this != &other)
	{
		for (int i = 0; i < 4; i++)
		{
			delete this->_storage[i];
			if (other._storage[i])
				this->_storage[i] = other._storage[i]->clone();
			else
				this->_storage[i] = NULL;
		}
	}
	return *this;
}

MateriaSource::~MateriaSource()
{
	std::cout << CYAN << "MateriaSource destructor called" << RESET << std::endl;
	for (int i = 0; i < 4; i++)
	{
		delete this->_storage[i];
	}
}

void	MateriaSource::learnMateria(AMateria* m)
{
	for (int i = 0; i < 4; i++)
	{
		if (!this->_storage[i])
		{
			this->_storage[i] = m;
			std::cout << CYAN << "It learned materia at " << i << RESET << std::endl;
			return;
		}
	}
	std::cout << CYAN << "All the 4 storage slots are already filled, cannot learn more materia" << RESET << std::endl;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_storage[i] && this->_storage[i]->getType() == type)
			return this->_storage[i]->clone();
	}
	return NULL;
}
