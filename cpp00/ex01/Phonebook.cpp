/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauldos- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 10:27:01 by pauldos-          #+#    #+#             */
/*   Updated: 2025/05/21 11:00:29 by pauldos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"
#include <cstdlib>

Phonebook::Phonebook(void)
{
	this->_index = 0;
	std::cout << " ___________________________________________________" << std::endl;
	std::cout << "|                                                   |" << std::endl;
	std::cout << "|  Hi, this is your new 8 contacts long phonebook   |" << std::endl;
	std::cout << "|  ADD command for adding a new contact             |" << std::endl;
	std::cout << "|  SEARCH command for searching a contact by index  |" << std::endl;
	std::cout << "|  EXIT command for exiting program                 |" << std::endl;
	std::cout << "|__________________________________________________ |" << std::endl;
}

Phonebook::~Phonebook(void)
{
	std::cout << "Thank you for using this Phonebook program. Good bye!" << std::endl;
}

std::string remove_tabs(const std::string &input)
{
	std::string	result;
	size_t		i;

	i = 0;
	while (i < input.length())
	{
		if (input[i] != '\t')
			result += input[i];
		i++;
	}
	return (result);
}


int ft_printable(const std::string &str)
{
	size_t i = 0;
	while (i < str.length())
	{
		if(!std::isprint(str[i]))
			return (0);
		i++;
	}
	return (1);
}
void	Phonebook::add(void)
{
	std::string	str;
	char		*end;
	long		num;	

	str = "";
	if (this->_index > 7)
		std::cout << "You are going to overwrite " << this->_contacts[this->_index % 8].get_fname() << std::endl;
	while (!std::cin.eof() && str == "")
	{
		std::cout << "Please enter first name: ";
		if (std::getline(std::cin, str) && str != "" && ft_printable(str))
				this->_contacts[this->_index % 8].set_fname(str);
		else
			str = "";
	}
	str = "";
	while (!std::cin.eof() && str == "")
	{
		std::cout << "Please enter " << this->_contacts[this->_index % 8].get_fname() << "'s last name: ";
		if (std::getline(std::cin, str) && str != "" && ft_printable(str))
				this->_contacts[this->_index % 8].set_lname(str);
		else
			str = "";
	}
	str = "";
	while (!std::cin.eof() && str == "")
	{
		std::cout << "Please enter " << this->_contacts[this->_index % 8].get_fname() << "' nickname: ";
		if (std::getline(std::cin, str) && str != "" && ft_printable(str))
			this->_contacts[this->_index % 8].set_nickname(str);
		else
			str = "";
	}
	str = "";
	while (!std::cin.eof() && str == "")
	{
		std::cout << "Please enter " << this->_contacts[this->_index % 8].get_fname() << "'s phone number: ";
		if (std::getline(std::cin, str) && !str.empty() && ft_printable(str))
		{
			num = std::strtol(str.c_str(), &end, 10);
			if (*end != '\0' || num < 0)
			{
				std::cerr << "Invalid phone number format! Please enter digits only." << std::endl;
				str = "";
			}
			else
				this->_contacts[this->_index % 8].set_phone_num(static_cast<unsigned long int>(num));
		}
		else
			str = "";
	}
	str = "";
	while (!std::cin.eof() && str == "")
	{
		std::cout << "Please enter " << this->_contacts[this->_index % 8].get_fname() << "' darkest secret: ";
		if (std::getline(std::cin, str) && str != "" && ft_printable(str))
			this->_contacts[this->_index % 8].set_secret(str);
		else
			str = "";
	}
	std::cout << "Successfully added contact index #" << this->_index % 8 + 1 << ", " << this->_contacts[this->_index % 8].get_fname() << std::endl;
	this->_index++;
}

void	Phonebook::output(Contact contact)
{
	std::cout << std::endl << "Getting contact information..." << std::endl;
	if (!contact.get_fname().size())
	{
		std::cerr << "Failed to get this contact information" << std::endl;
		return ;
	}
	contact.display_contact();
}

void	Phonebook::search(void)
{
	std::string	str;

	if (!display_search_menu(this->_contacts))
	{
		std::cout << std::endl << "Phonebook is empty!" << std::endl;
		return ;
	}
	while (!std::cin.eof())
	{
		std::cout << "Select an index: ";
		if (std::getline(std::cin, str) && !str.empty())
		{
			if (str.size() == 1 && str[0] >= '1' && str[0] <= '8' && this->_contacts[str[0] - '0' - 1].get_fname().size())
				break ;
		}
		if (!str.empty())
			std::cerr << "Invalid index!" << std::endl;
	}
	if (!std::cin.eof())
		this->output(this->_contacts[str[0] - '0' - 1]);
}

void Phonebook::add_predefined_contact(int index, std::string fname, std::string lname, 
                                       std::string nickname, unsigned long int phone, std::string secret)
{
	if (index < 0 || index >= 8)
		return;
	this->_contacts[index].set_fname(fname);
	this->_contacts[index].set_lname(lname);
	this->_contacts[index].set_nickname(nickname);
	this->_contacts[index].set_phone_num(phone);
	this->_contacts[index].set_secret(secret);
}

void Phonebook::set_index(int index)
{
	this->_index = index % 8;
}
