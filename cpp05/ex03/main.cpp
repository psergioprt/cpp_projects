/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauldos- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 11:25:01 by pauldos-          #+#    #+#             */
/*   Updated: 2025/10/09 13:36:46 by pauldos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <cstdlib>

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{

	AForm* form1 = NULL;
	AForm* form2 = NULL;
	AForm* form3 = NULL;
	AForm* invalidForm = NULL;

	try
	{
		Intern Mary;
		
		form1 = Mary.makeForm("ShrubberyCreationForm", "Home");
		form2 = Mary.makeForm("RobotomyRequestForm", "Bender");
		form3 = Mary.makeForm("PresidentialPardonForm", "Kruger");
		std::cout << std::endl;
		std::cout << "Form1 created: " << form1->getName() << std::endl;
		std::cout << "Form2 created: " << form2->getName() << std::endl;
		std::cout << "Form3 created: " << form3->getName() << std::endl;

	}
	catch (const std::exception& e)
	{
		std::cout << "Exception error: " << e.what() << std::endl;
	}
	std::cout << std::endl;
	try
	{
		Intern Joe;

		invalidForm = Joe.makeForm("InvalidForm", "Invalid");
		std::cout << "InvalidForm created: " << invalidForm->getName() << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "Exception error: " << e.what() << std::endl;
	}

	delete form1;
	delete form2;
	delete form3;
	delete invalidForm;
	return 0;
}
