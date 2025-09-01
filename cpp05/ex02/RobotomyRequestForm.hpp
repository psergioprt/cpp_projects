#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include<string>
#include "AForm.hpp"

class Bureaucrat;

class RobotomyRequestForm : public AForm
{
	private:
		std::string _target;
		
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(const std::string& target);
		RobotomyRequestForm(const RobotomyRequestForm& other);
		RobotomyRequestForm& operator=(const RobotomyRequestForm& other);
		~RobotomyRequestForm();

		void beExecuted(const Bureaucrat& executor) const;
};

#endif
