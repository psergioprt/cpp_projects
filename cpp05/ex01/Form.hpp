/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauldos- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 11:14:01 by pauldos-          #+#    #+#             */
/*   Updated: 2025/09/23 11:14:05 by pauldos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>
#include <exception>
#include "Bureaucrat.hpp"

class Form
{
	private:
		const std::string	_name;
		bool			_isSigned;
		const int		_signGrade;
		const int		_executeGrade;

	public:
		Form();
		Form(const std::string& name, int signGrade, int executeGrade);
		Form(const Form& other);
		Form& operator=(const Form& other);
		~Form();
		
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

		void beSigned(const Bureaucrat& bureaucrat);
};

std::ostream& operator<<(std::ostream& out, const Form& form);

#endif
