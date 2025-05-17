/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauldos- <pauldos-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 13:04:40 by pauldos-          #+#    #+#             */
/*   Updated: 2025/05/16 13:11:51 by pauldos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include <iostream>

Dog::Dog()
{
	this->type = "Dog";
	std::cout << "Dog constructor created!" << std::endl;
}

Dog::~Dog()
{
	std::cout << "Dog destroyed!" << std::endl;
}

void	Dog::makeSound() const
{
	std::cout << "woof woof" << std::endl;
}
