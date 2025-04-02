/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook_utils.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauldos- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 20:47:31 by pauldos-          #+#    #+#             */
/*   Updated: 2025/03/31 16:05:22 by pauldos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook_utils.hpp"

std::string	insert_padding(int n)
{
	std::string	str;

	while (n--)
		str.append(" ");
	return (str);
}

std::string	resize_str(std::string str, unsigned max)
{
	if (str.size() > max)
	{
		str.resize(max);
		str[str.size() - 1] = '.';
	}
	return (str);
}

int	display_search_menu(Contact contacts[8])
{
	char		c;
	int			i;
	int			max;
	std::string	str;

	std::cout << " ___________________________________________ " << std::endl;
	std::cout << "|     Index|First Name| Last Name|  Nickname|" << std::endl;
	std::cout << "|----------|----------|----------|----------|" << std::endl;
	c = '0';
	i = 0;
	max = 10;
	while (++c <= '8')
	{
		if (contacts[c - '0' - 1].get_fname().size() && ++i)
		{
			str = c;
			str = resize_str(str, max);
			std::cout << "|" << insert_padding(max - str.size()) << str;
			str = resize_str(contacts[c - '0' - 1].get_fname(), max);
			std::cout << "|" << insert_padding(max - str.size()) << str;
			str = resize_str(contacts[c - '0'- 1].get_lname(), max);
			std::cout << "|" << insert_padding(max - str.size()) << str;
			str = resize_str(contacts[c - '0' - 1].get_nickname(), max);
			std::cout << "|" << insert_padding(max - str.size()) << str << "|" << std::endl;
		}
	}
	std::cout << "|___________________________________________|" << std::endl;
	return (i);
}
