#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>

#include "RobotomyRequestForm.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm::AForm("RobotomyRequestForm", 72, 45),  _target("Default"){}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) : AForm::AForm("RobotomyRequestForm", 72, 45), _target(target){}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : AForm(other), _target(other._target){}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
	if (this != &other)
	{
		AForm::operator = (other);
		this->_target = other._target;
	}
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm(){}

void RobotomyRequestForm::beExecuted(const Bureaucrat& executor) const
{
	(void) executor;
	std::cout << "DRILLING NOISES" << std::endl;
	if (rand() % 2)
	{
		std::cout << this->_target << " has been robotomized successfully 50% of the time" << std::endl;
	}
	else
		std::cout << "Robotomy failed on " << this->_target << std::endl;
}
