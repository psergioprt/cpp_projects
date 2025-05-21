/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauldos- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 12:06:40 by pauldos-          #+#    #+#             */
/*   Updated: 2025/05/20 19:04:52 by pauldos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

int main()
{
	Animal a;
	Animal* a = new Animal();

	const	Animal* animals[4];

	for (int i = 0; i < 2; ++i)
		animals[i] = new Dog();
	for (int i = 2; i < 4; ++i)
		animals[i] = new Cat();

	std::cout << "\n--- Making sounds ---" << std::endl;
	for (int i = 0; i < 4; ++i)
		animals[i]->makeSound();

	for (int i = 0; i < 4; ++i)
		delete animals[i];

	std::cout << "\n--- Deep Copy Check ---" << std::endl;
	Dog original;
	original.setIdea(0, "Catch the ball");

	Dog copy = original;
	original.setIdea(0, "Chew the slipper");

	std::cout << "Original idea: " << original.getIdea(0) << std::endl;
	std::cout << "copied idea: " << copy.getIdea(0) << std::endl;

	return (0);
}
