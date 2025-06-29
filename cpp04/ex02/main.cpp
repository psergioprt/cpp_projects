/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauldos- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 09:20:05 by pauldos-          #+#    #+#             */
/*   Updated: 2025/06/29 01:58:42 by pauldos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include <iostream>

#define RESET "\033[0m"
#define YELLOW "\033[93m"
#define BGBLUE "\033[44m"

int main()
{

	/* Uncomment the lines below for proff that AAnimal cannot be instantiated in ex02
	 * This will produce a compile error because AAnimal is abstract.*/

	/*std::cout << std::endl;
	std::cout << BGBLUE YELLOW << "*** TEST FOR ex01(non abstract)/ex02(abstract) ***" << RESET <<std::endl;
	std::cout << BGBLUE YELLOW << "*** It will NOT compile at ex02 ***" << RESET <<std::endl;
	std::cout << std::endl;
	AAnimal a; //Cannot instantiate abstract class
	AAnimal* b = new AAnimal(); //Compiler error
	//delete b; //for ex01*/
	

	std::cout << std::endl;
	std::cout << BGBLUE YELLOW << "*** Creating 100 animal objects ***" << RESET <<std::endl;
	std::cout << std::endl;
	
	const	AAnimal* animals[100];

	for (int i = 0; i < 100; i++)
	{
		if (i < 50)
			animals[i] = new Dog;
		else
			animals[i] = new Cat;
	}
	std::cout << std::endl;
	
	std::cout << BGBLUE YELLOW << "*** Outputing those 100 animal sounds (50 dogs + 50 cats) ***" << RESET <<std::endl;
	std::cout << std::endl;
	for (int i = 0; i < 100; i++)
		animals[i]->makeSound();
	
	std::cout << std::endl;
	std::cout << BGBLUE YELLOW << "*** Deleting those 100 animal objects ***" << RESET <<std::endl;
	std::cout << std::endl;
	for (int i = 0; i < 100; i++)
		delete animals[i];
	
	std::cout << std::endl;	
	std::cout << BGBLUE YELLOW << "*** Creating objects ***" << RESET <<std::endl;
	std::cout << std::endl;

	const AAnimal* j = new Dog();
	const AAnimal* i = new Cat();

	delete j;
	delete i;

	std::cout << std::endl;
	std::cout << BGBLUE YELLOW << "*** Dog: Deepcopy test ***" << RESET <<std::endl;
	std::cout << std::endl;

	Dog dog1;
	dog1.setIdea(0, "Chase the cat");
	dog1.setIdea(1, "Bark at the mailman");

	Dog dog2 = dog1;

	dog1.setIdea(0, "Dig a hole");

	std::cout << "Dog1 Idea[0]" << dog1.getIdea(0) << std::endl;
	std::cout << "Dog2 Idea[0]" << dog2.getIdea(0) << std::endl;
	std::cout << "Dog1 Idea[1]" << dog1.getIdea(1) << std::endl;
	std::cout << "EMPTY Dog2 Idea[2]" << dog2.getIdea(2) << std::endl;
	std::cout << "OUT OF BOUNDS Dog2 Idea[110]" << dog2.getIdea(110) << std::endl;
	
	std::cout << std::endl;
	std::cout << BGBLUE YELLOW << "*** Cat: Deepcopy test ***" << RESET <<std::endl;
	std::cout << std::endl;

	Cat cat1;
	Cat cat2;

	cat1.setIdea(35, "Taking a nap");
	cat1.setIdea(70, "Climbing the courtains");
	
	cat2.setIdea(35, "Something else");
	cat2 = cat1;
	cat2.setIdea(35, "Anything else");

	std::cout << "Cat1[35]: " << cat1.getIdea(35) << std::endl;
	std::cout << "Cat1[70]: " << cat1.getIdea(70) << std::endl;
	std::cout << "Cat1[0]: "  << cat1.getIdea(0) << std::endl;
	std::cout << "Cat1[120]: " << cat1.getIdea(120) << std::endl;

	std::cout << "Cat2[35]: " << cat2.getIdea(35) << std::endl;
	std::cout << "Cat2[70]: " << cat2.getIdea(70) << std::endl;
	std::cout << "Cat2[0]: "  << cat2.getIdea(0) << std::endl;
	std::cout << "Cat2[120]: " << cat2.getIdea(120) << std::endl;


	std::cout << std::endl;
	std::cout << BGBLUE YELLOW << "*** Destructor called in reverse order ***" << RESET << std::endl;
	std::cout << std::endl;

	return 0;
}
