/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauldos- <pauldos-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 15:08:53 by pauldos-          #+#    #+#             */
/*   Updated: 2025/06/30 23:00:24 by pauldos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"
#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include <iostream>

#define RESET "\033[0m"
#define YELLOW "\033[93m"

int main()
{
	std::cout << std::endl;
	std::cout << YELLOW << "--- Subject main test ---" << RESET << std::endl;
	std::cout << std::endl;

	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter* me = new Character("me");

	AMateria* tmp;

	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	ICharacter* bob = new Character("bob");

	me->use(0, *bob);
	me->use(1, *bob);

	std::cout << std::endl;
	std::cout << YELLOW << "--- Additional Inventory Tests ---" << RESET << std::endl;
	std::cout << std::endl;
	
	std::cout << std::endl;
	std::cout << YELLOW << "--- 1 - Equip more materias to fill inventory ---" << RESET << std::endl;
	std::cout << std::endl;

	tmp = src->createMateria("ice");
	me->equip(tmp); // slot 2
	tmp = src->createMateria("cure");
	me->equip(tmp); // slot 3
	
	std::cout << std::endl;
	std::cout << YELLOW << "--- 2) Attempt to equip 5th materia (should be refused) ---" << RESET << std::endl;
	std::cout << std::endl;

	tmp = src->createMateria("ice");
	me->equip(tmp); // Should print refusal message


	// 3) Unequip invalid slot (e.g., slot 4) - nothing should happen
	me->unequip(4);

	// 4) Unequip valid slot (e.g., slot 2)
	me->unequip(2);

	//5) Test that slot 2 is empty by trying to use it (should do nothing)
	me->use(2, *bob);


	// 6) Try to use unequipped slot 2 (should print error / do nothing)
    	me->use(2, *bob);

	// 7) Equip NULL pointer (should be refused)
    	me->equip(NULL);

	delete bob;
	delete me;
	delete src;

	return 0;
}
