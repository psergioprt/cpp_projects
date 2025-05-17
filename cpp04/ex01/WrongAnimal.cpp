/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauldos- <pauldos-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 15:27:23 by pauldos-          #+#    #+#             */
/*   Updated: 2025/05/16 16:19:57 by pauldos-         ###   ########.fr       */
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
