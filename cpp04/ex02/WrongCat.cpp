/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauldos- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 11:14:14 by pauldos-          #+#    #+#             */
/*   Updated: 2025/06/27 22:26:44 by pauldos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "WrongCat.hpp"

#define RESET "\033[93m"
#define MAGENTA "\033[35m"

WrongCat::WrongCat()
{
	this->_type = "WrongCat";
	std::cout << MAGENTA << "WrongCat constructor created!" << RESET << std::endl;
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other)
{
	this->_type = other._type;
	std::cout << MAGENTA << "WrongCat copy constructor" << RESET << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& other)
{
	if (this != &other)
		this->_type = other._type;
	return *this;
	std::cout << MAGENTA << "WrongCat assignement operator" << RESET << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << MAGENTA << "WrongCat destroyed!" << RESET << std::endl;
}

void WrongCat::makeSound() const
{
	std::cout << MAGENTA << "meaw" << RESET << std::endl;
}
