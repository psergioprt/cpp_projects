/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauldos- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 10:30:31 by pauldos-          #+#    #+#             */
/*   Updated: 2025/04/28 11:28:41 by pauldos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(void)
{
	std::string brain;
	std::string *stringPTR;

	brain = "HI THIS IS BRAIN";
	stringPTR = &brain;
	std::string &stringREF = brain;

	std::cout << "address of brain: " << &brain << std::endl;
	std::cout << "address of brain using stringPTR: " << stringPTR << std::endl;
	std::cout << "address of brain using stringREF: " << &stringREF << std::endl;

	std::cout << "string using pointer: " << *stringPTR << std::endl;
	std::cout << "string using reference: " << stringREF << std::endl;

	return (0);

}
