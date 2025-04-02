/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 22:10:26 by pauldos-          #+#    #+#             */
/*   Updated: 2025/03/28 10:32:58 by pauldos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "Phonebook.hpp"
#include <limits>

int	main(void)
{
	Phonebook	ph;
	std::string	str;
	char		choice;

	choice = '\0';

	while (!std::cin.eof() && choice != 'Y' && choice != 'y' && choice != 'N' && choice != 'n')
	{
		std::cout << "Would you like 7 pre-filled contacts? y/n: ";
		std::cin >> choice;
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		if (choice == 'y' || choice == 'Y')
		{
			ph.set_index (7);
			ph.add_predefined_contact(0, "Nicole", "Kidman", "NK", 123456789, "Likes oranges");	
			ph.add_predefined_contact(1, "Tom", "Hanks", "TH", 5678976339, "Likes strawberries");	
			ph.add_predefined_contact(2, "Renee", "Zellweger", "RZ", 978736339, "Likes apples");
			ph.add_predefined_contact(3, "Tom", "Cruise", "TC", 98123456789, "Likes coconut");	
			ph.add_predefined_contact(4, "Meg", "Ryan", "MR", 2456976339, "Likes pinapple");	
			ph.add_predefined_contact(5, "John", "Malkovich", "JM", 56636339, "Likes mango");
			ph.add_predefined_contact(6, "Meryl", "Streep", "MS", 9898736339, "Likes pears");
		}
		else if (std::cin.eof())
		{
			std::cout << std::endl;
			return (0);
		}
	}
	while(str != "EXIT")
	{
		std::cout << "What would you like to do? ADD|SEARCH|EXIT > ";
		std::getline(std::cin, str);
		if (str == "ADD")
			ph.add();
		else if(str == "SEARCH")
			ph.search();
		if (std::cin.eof())
		{	
			std::cout << std::endl;
			return (0);
		}
	}
	return (0);
}
