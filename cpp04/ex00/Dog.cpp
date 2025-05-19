/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauldos- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 11:13:27 by pauldos-          #+#    #+#             */
/*   Updated: 2025/05/19 11:13:29 by pauldos-         ###   ########.fr       */
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
