/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauldos- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 11:10:44 by pauldos-          #+#    #+#             */
/*   Updated: 2025/06/25 07:28:34 by pauldos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

#define RESET "\033[0m"
#define YELLOW "\033[93m"
int main()
{
	std::cout << YELLOW << "TESTING ANIMAL" << RESET << std::endl;
	const	Animal* meta = new Animal();
	const	Animal* j = new Dog();
	const	Animal* i = new Cat();

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();

	delete meta;
	delete j;
	delete i;

	std::cout << std::endl;
	std::cout << YELLOW << "TESTING WRONG ANIMAL" << RESET << std::endl;
	const	WrongAnimal* test = new WrongAnimal();
	const	WrongAnimal* k = new WrongCat();
	std::cout << k->getType()  << " " << std::endl;
	test->makeSound();
	k->makeSound();

	delete test;
	delete k;
	
	return 0;
}
