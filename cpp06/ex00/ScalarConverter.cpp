#include <iostream>
#include <cerrno>
#include <climits>
#include <cstdlib>
#include <iomanip>
#include <cmath>

#include "ScalarConverter.hpp"

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

bool handlePseudoLiterals(const std::string& str)
{
	if (str.empty())
		return false;
	if (str == "nan" || str == "nanf")
	{
		std::cout << "char: impossible\nint: impossible\nfloat: nanf\ndouble: nan" << std::endl;
		return true;
	}
	if (str == "+inf" || str == "+inff" || str == "inf" || str == "inff")
	{
		std::cout << "char: impossible\nint: impossible\nfloat: +inff\ndouble: +inf" << std::endl;
		return true;
	}
	if (str == "-inf" || str == "-inff")
	{
		std::cout << "char: impossible\nint: impossible\nfloat: -inff\ndouble: -inf" << std::endl;
		return true;
	}
	return false;
}

bool handleNonDisplayableCharacters(const std::string& str)
{
	if (str.empty())
		return false;
	for (size_t i = 0; i < str.length(); i++)
	{
		unsigned char c = static_cast<unsigned char>(str[i]);
		if (c < 32 || c > 126)
		{
			std::cerr << "Invalid character" << std::endl;
			return true;
		}
	}
	return false;
}

bool detectCharType(const std::string& str, ScalarConverter::Type &type)
{
	if (str.length() == 1)
	{
		unsigned char c = static_cast<unsigned char>(str[0]);
		if (!(handleNonDisplayableCharacters(str)) && !(c >= '0' && c <= '9'))
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
	errno = 0;
	long value = std::strtol(str.c_str(), NULL, 10);
	if (errno == ERANGE || value < INT_MIN || value > INT_MAX)
	{
		std::cout << "Value out of range" << std::endl;
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

void ConvertValue(const std::string& str, ScalarConverter::Type &type)
{
	switch(type)
	{
		case ScalarConverter::CHAR:
		{
			char c = str[0];
			std::cout << "char: " << c << std::endl;
			std::cout << "int: " << static_cast<int>(c) << std::endl;
			std::cout << std::fixed << std::setprecision(1);
			std::cout << "float: " << static_cast<float>(c) << "f" << std::endl;
			std::cout << "double: " << static_cast<double>(c) << std::endl;
			break;
		}
		case ScalarConverter::INT:
		{
			int tmp = std::strtol(str.c_str(), NULL, 10);
			int i = static_cast<int>(tmp);
			if (i < 32 || i > 126)
				std::cout << "char: non_displayable" << std::endl;
			else
				std::cout << "char: " << static_cast<char>(i) << std::endl;
			std::cout << "int: " << i << std::endl;
			std::cout << std::fixed << std::setprecision(1);
			std::cout << "float: " << static_cast<float>(i) << "f" << std::endl;
			std::cout << "double: " << static_cast<double>(i) << std::endl;
			break;
		}
		case ScalarConverter::FLOAT:
		{
			float tmp = std::strtof(str.c_str(), NULL);
			int f = static_cast<int>(tmp);
			if (f < 32 || f > 126 || std::isnan(f))
				std::cout << "char: non_displayable" << std::endl;
			else
				std::cout << "char: " << static_cast<char>(f) << std::endl;
			std::cout << "int: " << f << std::endl;
			std::cout << std::fixed << std::setprecision(1);
			std::cout << "float: " << static_cast<float>(tmp) << "f" << std::endl;
			std::cout << "double: " << static_cast<double>(tmp) << std::endl;
			break;
		}
		case ScalarConverter::DOUBLE:
		{
			double tmp = std::strtod(str.c_str(), NULL);
			int d = static_cast<int>(tmp);
			if (d < 32 || d > 126 || std::isnan(d))
				std::cout << "Char: Char not visible" << std::endl;
			else
				std::cout << "char: " << static_cast<char>(d) << std::endl;
			std::cout << "int: " << static_cast<int>(d) << std::endl;
			std::cout << std::fixed << std::setprecision(1);
			std::cout << "float: " << static_cast<float>(tmp) << "f" << std::endl;
			std::cout << "double: " << static_cast<double>(tmp) << std::endl;
			break;
		}
		default:
			std::cout << "Not a valid type" << std::endl;

	}
}

void ScalarConverter::convert(const std::string& str, ScalarConverter::Type &type)
{
	type = ScalarConverter::UNKNOWN;

	if (handlePseudoLiterals(str))
		return;
	if (handleNonDisplayableCharacters(str))
		return;
	if (detectInputType(str, type))
	{
		ConvertValue(str, type);
		return;
	}
	std::cout << "Error: '" << str << "' is not a valid input" << std::endl;
}
