/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauldos- <pauldos-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 13:43:39 by pauldos-          #+#    #+#             */
/*   Updated: 2025/05/16 16:27:47 by pauldos-         ###   ########.fr       */
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
