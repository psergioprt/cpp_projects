/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauldos- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 11:14:10 by pauldos-          #+#    #+#             */
/*   Updated: 2025/09/23 11:14:13 by pauldos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : _name("default"), _isSigned(false), _signGrade(150), _executeGrade(150){}

Form::Form(const std::string& name, int signGrade, int executeGrade) : 
	_name(name), 
	_isSigned(false), 
	_signGrade(signGrade), 
	_executeGrade(executeGrade)
{
	if (signGrade < 1)
		throw GradeTooHighException();
	if (signGrade > 150)
		throw GradeTooLowException();
	if (executeGrade < 1)
		throw GradeTooHighException();
	if (executeGrade > 150)
		throw GradeTooLowException();
}

Form::Form(const Form& other) : 
	_name(other._name), 
	_isSigned(other._isSigned), 
	_signGrade(other._signGrade), 
	_executeGrade(other._executeGrade){}

Form& Form::operator=(const Form& other)
{
	if (this != &other)
		this->_isSigned = other._isSigned;
	return *this;
}

Form::~Form(){}

const std::string& Form::getName() const
{
	return this->_name;
}

bool Form::getIsSigned() const
{
	return this->_isSigned;
}

int Form::getSignGrade() const
{
	return this->_signGrade;
}

int Form::getExecuteGrade() const
{
	return this->_executeGrade;
}

const char * Form::GradeTooHighException::what() const throw()
{
		return "Grade is too High";
}

const char * Form::GradeTooLowException::what() const throw()
{
		return "Grade is too low";
}

void Form::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() > this->_signGrade)
		throw GradeTooLowException();
	else
		_isSigned = true;
}

std::ostream& operator<<(std::ostream& out, const Form& form)
{
	out << form.getName()
		<< ", form sign grade " << form.getSignGrade()
		<< ", execute grade " << form.getExecuteGrade()
		<< ", signed: " << (form.getIsSigned() ? "yes" : "no");
	return out;
}
