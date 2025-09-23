/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauldos- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 11:19:57 by pauldos-          #+#    #+#             */
/*   Updated: 2025/09/23 11:19:59 by pauldos-         ###   ########.fr       */
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
		Bureaucrat paul("Paul", 146);
		ShrubberyCreationForm form("garden");
		paul.signForm(form);
		form.execute(paul);
	}
	catch (std::exception& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
	
	std::cout << std::endl;
	std::cout << "ROBOTOMY REQUEST FORM" << std::endl;
	try
	{
		Bureaucrat simon("Simon", 45);
		RobotomyRequestForm robot("Bender");
		simon.signForm(robot);
		robot.execute(simon);
	}
	catch (std::exception& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
	
	std::cout << std::endl;
	std::cout << "* PRESIDENTIAL PARDON FORM *" << std::endl;

	try
	{
		Bureaucrat george("George", 4);
		PresidentialPardonForm presidential("Joe Doe");
		george.signForm(presidential);
		presidential.execute(george);
	}
	catch (std::exception& e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}
	return 0;
}
