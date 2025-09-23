/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauldos- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 11:13:22 by pauldos-          #+#    #+#             */
/*   Updated: 2025/09/23 11:13:29 by pauldos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

#include <iostream>
#include <string>

int main()
{
	try
	{
		Bureaucrat b1("Paulo", 50);
		for (int i = 0; i < 20; i++)
			b1.incrementGrade();
		std::cout << b1 << std::endl;
		for (int i = 0; i < 40; i++)
			b1.decrementGrade();
		std::cout << b1 << std::endl;
	}
	catch (std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::cout << "--- Overgraded ---" << std::endl;
	try
	{
		Bureaucrat b2("Sérgio", 151);
		std::cout << b2 << std::endl;
	}
	catch (std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::cout << "--- Downgraded ---" << std::endl;

	try
	{
		Bureaucrat b3("William", 10);
		for (int i = 0; i < 9; i++)
			b3.incrementGrade();
		std::cout << b3 << std::endl;
	}
	catch (std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	return 0;
}
