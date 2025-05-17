/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauldos- <pauldos-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 13:38:17 by pauldos-          #+#    #+#             */
/*   Updated: 2025/05/16 13:43:03 by pauldos-         ###   ########.fr       */
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
