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
		
		std::cout << "Subject output" << std::endl;
		form1 = Mary.makeForm("ShrubberyCreationForm", "Home");
		form2 = Mary.makeForm("RobotomyRequestForm", "Bender");
		form3 = Mary.makeForm("PresidentialPardonForm", "Kruger");
		invalidForm = Mary.makeForm("InvalidForm", "Joe");

		std::cout << std::endl;
		std::cout << "DEBUG: This lines won't be seen if an exception was thrown before" << std::endl;
		std::cout << "Form1 created: " << form1->getName() << std::endl;
		std::cout << "Form2 created: " << form2->getName() << std::endl;
		std::cout << "Form3 created: " << form3->getName() << std::endl;

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
