/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauldos- <pauldos-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 09:08:21 by pauldos-          #+#    #+#             */
/*   Updated: 2025/06/30 10:06:36 by pauldos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "AMateria.hpp"
#include "ICharacter.hpp"

#define RESET "\033[0m"
#define MAGENTA "\033[35m"

Cure::Cure() : AMateria()
{
	std::cout << MAGENTA << "Cure default constructor called" << RESET << std::endl;
	this->_type = "cure";
}

Cure::~Cure()
{
	std::cout << MAGENTA << "Cure destructor called" << RESET << std::endl;
}

Cure::Cure(const Cure& other)
{
	std::cout << MAGENTA << "Cure copy constructor" << RESET << std::endl;
	this->_type = other._type;
}

Cure& Cure::operator=(const Cure& other)
{
	std::cout << MAGENTA << "Cure copy assignment operator" << RESET << std::endl;
	if (this != &other)
		this->_type = other._type;
	return *this;
}

AMateria* Cure::clone() const
{
	return new Cure (*this);
}

void	Cure::use(ICharacter& target)
{
	std::cout << MAGENTA << "* heals " << target.getName() << "'s wounds *" << RESET << std::endl; 
}
