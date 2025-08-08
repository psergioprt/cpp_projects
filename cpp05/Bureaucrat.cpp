/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauldos- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 15:31:31 by pauldos-          #+#    #+#             */
/*   Updated: 2025/08/08 17:13:57 by pauldos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("default"), _grade(150){}

Bureaucrat::Bureaucrat(const std::string& name, int grade) : _name(name)
{
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
	_grade = grade;
}

Bureaucrat::Bureaucrat(const bureaucrat& other) : _name(other._name), _grade(other.grade){}

Bureaucrat& operator=(const bureaucrat& other)
{
	if (this != &other)
	{
		this->_grade = other._grade;
	}
	return *this;
}

~Bureaucrat(){}

const std::string getName() const;
		int getGrade() const;

		void incrementGrade();
		void decrementGrade();

		class GradeTooHighException : public std::exception
		{
			public:
				const char * what() const no except override;
		};
		class GradeTooLowException : public std::exception
		{
			public:
				const char * what() const no except override;
		};


std::ostream& operator<<(std::ostream& out, const Bureaucrat& other);

