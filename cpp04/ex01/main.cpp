/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauldos- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 09:20:05 by pauldos-          #+#    #+#             */
/*   Updated: 2025/05/20 11:03:31 by pauldos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include <iostream>

int main()
{
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	delete j;
	delete i;

	std::cout << "*** Deepcopy test ***" << std::endl;

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

	return 0;
}
