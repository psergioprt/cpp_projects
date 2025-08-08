/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauldos- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 15:31:31 by pauldos-          #+#    #+#             */
/*   Updated: 2025/08/08 16:03:42 by pauldos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureucrat.hpp"

Burocrat::Bureaucrat() : _name(""), _grade(0){}

Bureaucrat(const std::string& name)_name(name){}

Bureaucrat(const bureaucrat& other)
{
	this->_name = other._name;
	this->_grade = other._grade;
}

Bureaucrat& operator=(const bureaucrat& other)
{
	if (this != &other)
	{
		this->_name = other._name;
		this->_grade = other._grade;
	}
	return *this;
}

~Bureaucrat(){}

std::string getName() const
{
	return this->_name;
}

int getGrade() const
{
	return this->_grade;
}

void setGrade(int grade)
{
	if (grade > 0 && grade <= 150)
	{
		try
		{

		}
		catch (std::exception & e)
		{

		}
	}


}

void setName(const std::string);

std::ostream& operator<<(std::ostream& out, const Bureaucrat& other);

