/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauldos- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 11:10:44 by pauldos-          #+#    #+#             */
/*   Updated: 2025/05/19 11:10:47 by pauldos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

int main()
{
	const	Animal* meta = new Animal();
	const	Animal* j = new Dog();
	const	Animal* i = new Cat();

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();

	std::cout << "\n* Testing WrongAnimal\n";
	const	WrongAnimal* test = new WrongAnimal();
	const	WrongAnimal* k = new WrongCat();
	std::cout << k->getType()  << " " << std::endl;
	test->makeSound();
	k->makeSound();

	delete meta;
	delete j;
	delete i;
	delete test;
	delete k;
	
	return 0;
}
