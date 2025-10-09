/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauldos- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 11:19:57 by pauldos-          #+#    #+#             */
/*   Updated: 2025/10/09 12:55:49 by pauldos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <cstdlib>

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	srand(time(NULL));
	std::cout << "* SHRUBBERY CREATION FORM (145/137) *" << std::endl;
	try
	{
		Bureaucrat b1("Paul", 120);
		ShrubberyCreationForm form("garden");
		b1.signForm(form);
		b1.executeForm(form);
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	
	std::cout << std::endl;
	std::cout << "* ROBOTOMY REQUEST FORM (72/45) *" << std::endl;
	try
	{
		Bureaucrat b2("Simon", 30);
		RobotomyRequestForm robot("Bender");
		b2.signForm(robot);
		b2.executeForm(robot);
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	
	std::cout << std::endl;
	std::cout << "* PRESIDENTIAL PARDON FORM (25/5)*" << std::endl;

	try
	{
		Bureaucrat b3("George", 2);
		PresidentialPardonForm presidential("Joe Doe");
		b3.signForm(presidential);
		b3.executeForm(presidential);
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	return 0;
}
