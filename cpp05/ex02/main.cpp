/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauldos- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 11:19:57 by pauldos-          #+#    #+#             */
/*   Updated: 2025/10/08 13:24:23 by pauldos-         ###   ########.fr       */
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
	std::cout << "* SHRUBBERY CREATION FORM *" << std::endl;
	try
	{
		Bureaucrat b1("Paul", 110);
		ShrubberyCreationForm form("garden");
		b1.signForm(form);
		form.execute(b1);
	}
	catch (std::exception& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
	
	std::cout << std::endl;
	std::cout << "ROBOTOMY REQUEST FORM" << std::endl;
	try
	{
		Bureaucrat b2("Simon", 45);
		RobotomyRequestForm robot("Bender");
		b2.signForm(robot);
		robot.execute(b2);
	}
	catch (std::exception& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
	
	std::cout << std::endl;
	std::cout << "* PRESIDENTIAL PARDON FORM *" << std::endl;

	try
	{
		Bureaucrat b3("George", 4);
		PresidentialPardonForm presidential("Joe Doe");
		b3.signForm(presidential);
		presidential.execute(b3);
	}
	catch (std::exception& e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}
	return 0;
}
