/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauldos- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 12:02:01 by pauldos-          #+#    #+#             */
/*   Updated: 2025/05/19 12:24:32 by pauldos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

Brain::Brain()
{
	std::cout << "Brain constructor created!" << std::endl;
}

Brain::~Brain()
{
	std::cout << "Brain destructor called!" << std::endl;
}

Brain::Brain(const Brain& other)
{
	for (int i = 0; i < 100; i++)
	{
		this->ideas[i] = other._ideas[i];
	}
}

Brain& Brain::operator=(const Brain& other)
{
	if (this != &other._ideas)
	{
		for (int i = 0; i < 100; i++)
			this->_ideas[i] = other->_ideas[i];
	}
	return *this

}
