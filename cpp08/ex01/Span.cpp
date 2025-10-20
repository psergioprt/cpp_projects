/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauldos- <pauldos-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 09:19:30 by pauldos-          #+#    #+#             */
/*   Updated: 2025/10/20 11:57:22 by pauldos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include "Span.hpp"
#include <climits>
#include <iostream>

Span::Span() : _N(0){}

Span::Span(unsigned int N) : _N(N), _numbers(){}

Span::Span(const Span& other) : _N(other._N), _numbers(other._numbers){}

Span& Span::operator=(const Span& other)
{
	if (this != &other)
	{
		this->_N = other._N;
		this->_numbers = other._numbers;
	}
	return *this;
}

Span::~Span(){}

void Span::addNumber(int n)
{
	if (_numbers.size() == _N)
		throw VectorNumbersLimitAchievedException();
	else
		_numbers.push_back(n);
}

const char * Span::VectorNumbersLimitAchievedException::what() const throw()
{
	return "Vector cannot add any more numbers";
}

int Span::shortestSpan() const
{
	if (_numbers.size() < 2)
		throw LessThanTwoMembersException();
	
	std::vector<int> tmp = _numbers;
	std::sort(tmp.begin(), tmp.end());
	
	int shortest = INT_MAX;
	for (size_t i = 1; i < tmp.size(); i++)
	{
		int diff = tmp[i] - tmp[i - 1];
		if (diff < shortest)
			shortest = diff;
	}
	return shortest;
}

int Span::longestSpan() const
{
	if (_numbers.size() < 2)
		throw LessThanTwoMembersException();

	std::vector<int> tmp = _numbers;
	std::sort(tmp.begin(), tmp.end());
	int longest = tmp.back() - tmp.front();
	return longest;
}

const char * Span::LessThanTwoMembersException::what() const throw()
{
	return "Vector has less than two numbers";
}
