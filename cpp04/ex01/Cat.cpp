/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauldos- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 11:02:06 by pauldos-          #+#    #+#             */
/*   Updated: 2025/05/19 11:02:09 by pauldos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Cat.hpp"

Cat::Cat()
{
	this->type = "Cat";
	std::cout << "Cat constructor created!" << std::endl;
}

Cat::~Cat()
{
	std::cout << "Cat destroyed!" << std::endl;
}

void	Cat::makeSound() const
{
	std::cout << "miauuuuu" << std::endl;
}
