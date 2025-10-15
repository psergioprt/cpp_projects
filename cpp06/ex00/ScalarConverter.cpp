/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauldos- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 11:27:36 by pauldos-          #+#    #+#             */
/*   Updated: 2025/10/15 12:54:45 by pauldos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cerrno>
#include <limits>
#include <cstdlib>
#include <iomanip>
#include <cmath>
#include <climits>
#include "ScalarConverter.hpp"
#include <sstream>

ScalarConverter::ScalarConverter(){}

ScalarConverter::ScalarConverter(const ScalarConverter& other)
{
	(void) other;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other)
{
	(void) other;
	return *this;
}

ScalarConverter::~ScalarConverter(){}

bool	handlePseudoLiterals(const std::string& str)
{
	if (str.empty())
		return false;
	char* end = NULL;

	errno = 0;
	double d = std::strtod(str.c_str(), &end);
	
	if ((*end != '\0' && !(*end == 'f' && *(end + 1) == '\0')) || errno == ERANGE)
		return false;
	if (!std::isnan(d) && !std::isinf(d))
		return false;
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	float f = static_cast<float>(d);
	std::cout << std::fixed;
	if (std::isnan(d))
	{
		std::cout << "float: " << f << "f" << std::endl;
		std::cout << "double: " << d << std::endl;
	}
	else if (std::isinf(d))
	{
		if (d > 0)
		{
			std::cout << "float: +" << f << "f" << std::endl;
			std::cout << "double: +" << d << std::endl;
		}
		else
		{
			std::cout << "float: " << f << "f" << std::endl;
			std::cout << "double: " << d << std::endl;
		}
	}
	return true;
}

bool detectCharType(const std::string& str, ScalarConverter::Type &type)
{
	if (str.empty())
		return false;
	if (str.length() == 1)
	{
		unsigned char c = static_cast<unsigned char>(str[0]);
		if (c >= '0' && c <= '9')
			return false;
		if (c >= 32 && c <= 126)
		{
			type = ScalarConverter::CHAR;
			return true;
		}
	}
	return false;
}

bool detectIntType(const std::string& str, ScalarConverter::Type &type)
{
	if(str.empty())
		return false;
	size_t i = 0;
	if (str[0] == '+' || str[0] == '-')
		i = 1;
	if (str.length() == i)
		return false;
	for (; i < str.length(); i++)
	{
		unsigned char c = static_cast<unsigned char>(str[i]);
		if (!(c >= '0' && c <= '9'))
			return false;
	}
	type = ScalarConverter::INT; 
	return true;
}

bool detectFloatDoubleType(const std::string& str, ScalarConverter::Type &type)
{
	if (str.empty())
		return false;
	size_t i = 0;
	size_t count_point = 0;
	size_t count_e = 0;
	
	if (str[0] == '+' || str[0] == '-')
		i = 1;
	if (str.length() == i)
		return false;
	for (size_t k = 0; k < str.length() - 1; k++)
	{
		unsigned char d = static_cast<unsigned char>(str[k]);
		if (d == '.')
			count_point++;
		if (d == 'e' || d == 'E')
		{
			if (k == i)
				return false;
			if (k == str.length() - 1)
				return false;
			if(!isdigit(str[k - 1]))
				return false;
			if (k + 1 >= str.length())
				return false;
			if (!(isdigit(str[k +  1]) || str[k + 1] == '+' || str[k + 1] == '-'))
				return false;
			count_e++;
		}
	}
	if (count_point > 1 || count_e > 1)
		return false;
	if (count_point == 0 && count_e == 0)
		return false;
	for (; i < str.length(); i++)
	{
		unsigned char c = static_cast<unsigned char>(str[i]);

		if (isdigit(c))
			continue;
		if (c == '.' || c == 'e' || c == 'E')
			continue;
		if (c == 'f' && i == str.length() - 1)
			continue;
		if ((c == '+' || c == '-') && (str[i - 1] == 'e' || str[i - 1] == 'E'))
			continue;
		return false;
	}
	if (str[str.length() - 1] == 'f')
		type = ScalarConverter::FLOAT;
	else if (str[str.length() - 1] != 'f')
		type = ScalarConverter::DOUBLE;
	return true;
}

bool detectInputType(const std::string& str, ScalarConverter::Type &type)
{
	if (detectCharType(str, type))
		return true;
	if (detectIntType(str, type))
		return true;
	if (detectFloatDoubleType(str, type))
		return true;
	return false;
}

void caseChar(const std::string& str)
{
	char c = str[0];

	if (std::isprint(c))
		std::cout << "char: '" << c << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << std::fixed << std::setprecision(1);
	std::cout << "float: " << static_cast<float>(c) << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(c) << std::endl;
}

void caseInt(const std::string& str)
{
	long tmp = std::strtol(str.c_str(), NULL, 10);
	if (tmp < std::numeric_limits<int>::min() || tmp > std::numeric_limits<int>::max())
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
	}
	else
	{
		int i = static_cast<int>(tmp);
		if ((i >= 0 && i < 32)  || i == 127)
			std::cout << "char: Non displayable" << std::endl;
		else if (i < 0 || i > 127)
			std::cout << "char: out of ASCII range" << std::endl;
		else
			std::cout << "char: '" << static_cast<char>(i) << "'" << std::endl;
		std::cout << "int: " << i << std::endl;
	}
	std::cout << "float: " << static_cast<float>(tmp) << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(tmp) << std::endl;
}

void caseFloat(const std::string& str)
{
	float tmp = std::strtof(str.c_str(), NULL);

	if (std::isnan(tmp) || std::isinf(tmp))
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: " << tmp << "f" << std::endl;
		std::cout << "double: " << static_cast<double>(tmp) << std::endl;
		return;
	}
	if (tmp < 0 || tmp > 127)
		std::cout << "char: out of ASCII range" << std::endl;
	else if (!std::isprint(static_cast<char>(tmp)))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(tmp) << "'" << std::endl;
	if (tmp < std::numeric_limits<int>::min() || tmp > std::numeric_limits<int>::max())
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(tmp) << std::endl;
	std::cout << "float: " << tmp << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(tmp) << std::endl;
}

void caseDouble(const std::string& str)
{
	double tmp = std::strtod(str.c_str(), NULL);
	if (std::isnan(tmp) || std::isinf(tmp))
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: " << static_cast<float>(tmp) << "f" << std::endl;
		std::cout << "double: " << tmp << std::endl;
		return;
	}
	if (tmp < 0 || tmp > 127)
		std::cout << "char: out of ASCII range" << std::endl;
	else if (!std::isprint(static_cast<char>(tmp)))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(tmp) << "'" << std::endl;
	if (tmp < std::numeric_limits<int>::min() || tmp > std::numeric_limits<int>::max())
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(tmp) << std::endl;
	std::cout << "float: " << static_cast<float>(tmp) << "f" << std::endl;
	std::cout << "double: " << tmp << std::endl;
}

void ConvertValue(const std::string& str, ScalarConverter::Type &type)
{
	switch(type)
	{
		case ScalarConverter::CHAR:
			caseChar(str); break;
		case ScalarConverter::INT:
			caseInt(str); break;
		case ScalarConverter::FLOAT:
			caseFloat(str); break;
		case ScalarConverter::DOUBLE:
			caseDouble(str); break;
		default:
			std::cout << "Not a valid type" << std::endl;
	}
}

void invalid_input_string(const std::string& str)
{
	std::cerr << "Invalid literal: " << str << std::endl;
}
void ScalarConverter::convert(const std::string& str, ScalarConverter::Type &type)
{
	type = ScalarConverter::UNKNOWN;

	if (handlePseudoLiterals(str))
		return;
	if (detectInputType(str, type))
	{
		ConvertValue(str, type);
		return;
	}
	invalid_input_string(str);
}
