/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauldos- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 10:19:46 by pauldos-          #+#    #+#             */
/*   Updated: 2025/04/01 23:53:56 by pauldos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"
#include "Phonebook_utils.hpp"
#include <cstdlib>

class	Phonebook
{
	private:
		Contact	_contacts[8];
		int	_index;
	public:
		Phonebook(void);
		~Phonebook(void);
		void	add(void);
		void	search(void);
		void	output(Contact contact);
		void	add_predefined_contact(int index, std::string fname, std::string lname,
                                std::string nickname, unsigned long int phone, std::string secret);
		void	set_index(int index);
};

#endif
