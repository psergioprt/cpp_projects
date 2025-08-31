#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <string>
#include <exception>
#include "Bureaucrat.hpp"

class AForm
{
	private:
		const std::string	_name;
		bool			_isSigned;
		const int		_signGrade;
		const int		_executeGrade;

	public:
		AForm();
		AForm(const std::string& name, int signGrade, int executeGrade);
		AForm(const AForm& other);
		AForm& operator=(const AForm& other);
		virtual ~AForm();
		
		const	std::string& 	getName() const;
		bool			getIsSigned() const;
		int			getSignGrade() const;
		int			getExecuteGrade() const;

		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char * what() const throw(); 
		};
		
		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char * what() const throw();
		};

		class NotAllowedToSignException : public std::exception
		{
			public:
				virtual const char * what() const throw();
		};

		void beSigned(const Bureaucrat& bureaucrat);
		void execute(const Bureaucrat& executer) const;
		virtual void beExecuted(const Bureaucrat& executer) const = 0;
};

std::ostream& operator<<(std::ostream& out, const AForm& form);

#endif
