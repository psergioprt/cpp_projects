/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauldos- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 11:55:56 by pauldos-          #+#    #+#             */
/*   Updated: 2025/05/20 21:31:07 by pauldos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <string>

class Contact
{
	private:
		std::string _fname;
		std::string _lname;
		std::string _nickname;
		unsigned long int _phone_num;
		std::string _secret;

	public:
		Contact();	//Constructor
		~Contact();	//Destructor
	
	/*Getters*/
	std::string get_fname(void) const;
	std::string get_lname(void) const;
	std::string get_nickname(void) const;
	unsigned long int get_phone_num(void) const;
	std::string get_secret(void) const;

	void	display_contact() const;

	/*Setters*/
	void	set_fname(const std::string &str);
	void	set_lname(const std::string &str);
	void	set_nickname(const std::string &str);
	void	set_phone_num(const unsigned long int &nbr);
	void	set_secret(const std::string &str);
};

#endif
