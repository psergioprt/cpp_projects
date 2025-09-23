/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauldos- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 11:23:53 by pauldos-          #+#    #+#             */
/*   Updated: 2025/09/23 11:23:56 by pauldos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Intern.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern(){}

Intern::Intern(const Intern& other)
{
	(void)other;
}

Intern& Intern::operator=(const Intern& other)
{
	(void)other;
	return *this;
}

Intern::~Intern(){}

AForm * Intern::makeForm(const std::string& formName, const std::string& target) const
{
	std::string formNames[3] =
	{
		"ShrubberyCreationForm",
		"RobotomyRequestForm",
		"PresidentialPardonForm"
	};

	int i = 0;

	for (; i < 3 && (formNames[i] != formName); i++){}

	switch(i)
	{
		case 0:
			std::cout << "Intern creates " << formName << std::endl;
			return new ShrubberyCreationForm(target);
		case 1:
			std::cout << "Intern creates " << formName << std::endl;
			return new RobotomyRequestForm(target);
		case 2:
			std::cout << "Intern creates " << formName << std::endl;
			return new PresidentialPardonForm(target);
		default:
			throw AForm::InvalidFormException();	 
	}
}
