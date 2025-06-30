/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauldos- <pauldos-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 13:10:21 by pauldos-          #+#    #+#             */
/*   Updated: 2025/06/30 15:38:40 by pauldos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ICharacter.hpp"
#include "Ice.hpp"
#include "AMateria.hpp"

#define RESET "\033[0m"
#define BBLUE "\033[94m"

Ice::Ice() : AMateria("ice")
{
	std::cout << BBLUE << "Ice default constructor called" << RESET << std::endl;
}

Ice::~Ice()
{
	std::cout << BBLUE << "Ice destructor called" << RESET << std::endl;
}

Ice::Ice(const Ice& other) : AMateria(other)
{
	std::cout << BBLUE << "Ice copy constructor" << RESET << std::endl;
}

Ice& Ice::operator=(const Ice& other)
{
	std::cout << BBLUE << "Ice copy assignment operator" << RESET << std::endl;
	if (this != &other)
		AMateria::operator=(other);
	return *this;
}

AMateria* Ice::clone() const
{
	return new Ice(*this);	
}

void Ice::use(ICharacter& target)
{
	std::cout << BBLUE << "* shoots an ice bolt at " << target.getName() << " *" << RESET << std::endl;
}
