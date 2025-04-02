/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauldos- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 20:57:42 by pauldos-          #+#    #+#             */
/*   Updated: 2025/04/01 12:10:53 by pauldos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(void)
{
}

Contact::~Contact(void)
{
}

std::string	Contact::get_fname(void) const
{
	return (this->_fname);
}

std::string	Contact::get_lname(void) const
{
	return (this->_lname);
}

std::string	Contact::get_nickname(void) const
{
	return (this->_nickname);
}

unsigned long int	Contact::get_phone_num(void) const
{
	return (this->_phone_num);
}

std::string	Contact::get_secret(void) const
{
	return (this->_secret);
}

void	Contact::display_contact() const
{
	std::cout << "First name: " << get_fname() << std::endl;
	std::cout << "Last name: " << get_lname() << std::endl;
	std::cout << "Nickname: " << get_nickname() << std::endl;
	std::cout << "Phone number: " << get_phone_num() << std::endl;
	std::cout << "Darkest secret: " << get_secret() << std::endl;
}

void	Contact::set_fname(const std::string &str)
{
	this->_fname = str;
}

void	Contact::set_lname(const std::string &str)
{
	this->_lname = str;
}

void	Contact::set_nickname(const std::string &str)
{
	this->_nickname = str;
}

void	Contact::set_phone_num(const unsigned long int &nbr)
{
	this->_phone_num = nbr;
}

void	Contact::set_secret(const std::string &str)
{
	this->_secret = str;
}
