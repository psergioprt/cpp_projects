/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauldos- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 11:13:53 by pauldos-          #+#    #+#             */
/*   Updated: 2025/05/19 11:13:56 by pauldos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	this->type = "wrongAnimal";
	std::cout << "wrongAnimal constructor created!" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "wrongAnimal destroyed!" << std::endl;
}

std::string WrongAnimal::getType() const
{
	return this->type;
}

void	WrongAnimal::makeSound() const
{
	std::cout << "* generic animal sound *" << std::endl;
}
