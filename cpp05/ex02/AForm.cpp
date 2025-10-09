/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauldos- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 11:16:48 by pauldos-          #+#    #+#             */
/*   Updated: 2025/10/09 12:50:44 by pauldos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : _name("default"), _isSigned(false), _signGrade(150), _executeGrade(150){}

AForm::AForm(const std::string& name, int signGrade, int executeGrade) : 
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

AForm::AForm(const AForm& other) : 
	_name(other._name), 
	_isSigned(other._isSigned), 
	_signGrade(other._signGrade), 
	_executeGrade(other._executeGrade){}

AForm& AForm::operator=(const AForm& other)
{
	if (this != &other)
		this->_isSigned = other._isSigned;
	return *this;
}

AForm::~AForm(){}

const std::string& AForm::getName() const
{
	return this->_name;
}

bool AForm::getIsSigned() const
{
	return this->_isSigned;
}

int AForm::getSignGrade() const
{
	return this->_signGrade;
}

int AForm::getExecuteGrade() const
{
	return this->_executeGrade;
}

const char * AForm::GradeTooHighException::what() const throw()
{
		return "Grade is too High";
}

const char * AForm::GradeTooLowException::what() const throw()
{
		return "Grade is too low";
}

const char * AForm::NotAllowedToSignException::what() const throw()
{
	return "Form cannot be signed. Grade too low!";
}

const char * AForm::NotAllowedToExecuteException::what() const throw()
{
	return "Form cannot be executed. Grade too low!";
}

void AForm::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() > this->_signGrade)
		throw GradeTooLowException();
	else
		_isSigned = true;
}

void AForm::execute(const Bureaucrat& executor) const
{
	if (!getIsSigned() || executor.getGrade() > getExecuteGrade())
		throw NotAllowedToExecuteException();
	beExecuted(executor);
}

std::ostream& operator<<(std::ostream& out, const AForm& form)
{
	out << form.getName()
		<< ", form sign grade " << form.getSignGrade()
		<< ", execute grade " << form.getExecuteGrade()
		<< ", signed: " << (form.getIsSigned() ? "yes" : "no");
	return out;
}
