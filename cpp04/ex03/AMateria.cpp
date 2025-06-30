/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauldos- <pauldos-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 09:56:41 by pauldos-          #+#    #+#             */
/*   Updated: 2025/06/30 15:17:21 by pauldos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ICharacter.hpp"
#include "AMateria.hpp"

#define RESET "\033[0m"
#define BLUE "\033[34m"

AMateria::AMateria(std::string const &type) : _type(type)
{
	std::cout << BLUE << "AMateria constructor called" << RESET << std::endl;
}

AMateria::~AMateria()
{
	std::cout << BLUE << "AMateria destructor called" << RESET << std::endl;
}

AMateria::AMateria(const AMateria& other)
{
	std::cout << BLUE << "AMateria copy constructor called" << RESET << std::endl;
	this->_type = other._type;
}

AMateria& AMateria::operator=(const AMateria& other)
{
	std::cout << BLUE << "AMateria copy assigment operator called" << RESET << std::endl;
	if (this != &other)
		this->_type = other._type;
	return *this;
}

std::string const & AMateria::getType() const
{
	return this->_type;
}

void	AMateria::use(ICharacter& target)
{
	std::cout << BLUE << "AMateria used on " << target.getName() << RESET << std::endl;
}
