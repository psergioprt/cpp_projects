/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauldos- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 11:19:28 by pauldos-          #+#    #+#             */
/*   Updated: 2025/10/09 12:27:56 by pauldos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm::AForm("ShrubberyCreationForm", 145, 137), _target("default"){}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target) : AForm::AForm("ShrubberyCreationForm", 145, 137), _target(target){}


ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : AForm(other), _target(other._target){}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	if (this != &other)
	{
		AForm::operator = (other);
		this->_target = other._target;
	}
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm(){}

void ShrubberyCreationForm::beExecuted(const Bureaucrat& executor) const
{
	(void)executor;
	std::ofstream outfile((_target + "_shrubbery").c_str());
	if (!outfile)
	{
		std::cerr << "Could not open file" << std::endl;
		return ;
	}
	outfile << "   ^   " << std::endl;
	outfile << "  ^^^  " << std::endl;
	outfile << " ^^^^^ " << std::endl;
	outfile << "  |||  " << std::endl;
	outfile.close();
}
