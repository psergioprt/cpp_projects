/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauldos- <pauldos-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 08:11:31 by pauldos-          #+#    #+#             */
/*   Updated: 2025/10/20 16:45:26 by pauldos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <iterator>
#include <exception>
#include <vector>

class Span
{
	private:
		unsigned int _N;
		std::vector<int> _numbers;

	public:
		Span();
		Span(unsigned int N);
		Span(const Span& other);
		Span& operator=(const Span& other);
		~Span();

		void addNumber(int n);

		int shortestSpan() const;
		int longestSpan() const;
		
		class LessThanTwoMembersException : public std::exception
		{
			public:
				virtual const char * what() const throw();
		};

		class VectorNumbersLimitAchievedException : public std::exception
		{
			public:
				virtual const char * what() const throw();
		};
	};
#endif
