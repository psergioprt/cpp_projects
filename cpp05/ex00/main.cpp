#include "Bureaucrat.hpp"

#include <iostream>
#include <string>

int main()
{
	try
	{
		Bureaucrat b1("Paulo", 50);
		std::cout << b1 << std::endl;
		for (int i = 0; i < 10; i++)
			b1.incrementGrade();
		std::cout << b1 << std::endl;
		for (int i = 0; i < 30; i++)
			b1.decrementGrade();
		std::cout << b1 << std::endl;
	}
	catch (std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl; 
	}
	std::cout << "----------- Overgraded --------------" << std::endl;
	try
	{
		Bureaucrat b2("Sergio", 1);
		std::cout << b2 << std::endl;
		b2.incrementGrade();
		std::cout << b2 << std::endl;
	}
	catch (std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	std::cout << "------- Value to lower graded --------" << std::endl;
	try
	{
		Bureaucrat b3("Adam", 150);
		std::cout << b3 << std::endl;
		b3.decrementGrade();
		std::cout << b3 << std::endl;
	}
	catch (std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	std::cout << "------- Over initialized value --------" << std::endl;
	try
	{
		Bureaucrat b4("Tom", 0);
		std::cout << b4 << std::endl;
	}
	catch (std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	std::cout << "------- Too low initialized value ------" << std::endl;
	try
	{
		Bureaucrat b5("James", 151);
		std::cout << b5 << std::endl;
	}
	catch (std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	return 0;
}
