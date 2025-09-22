#include <iostream>
#include <cerrno>
#include <climits>
#include <cstdlib>

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
	if (str == "+inf" || str == "+inff")
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

bool detectCharType(const std::string& str)
{
	if (str.length() == 1)
	{
		unsigned char c = static_cast<unsigned char>(str[0]);
		if (!(handleNonDisplayableCharacters(str)) && !(c >= '0' && c <= '9'))
		{
			std::cout << "Is CHAR!!!" << std::endl;
			return true;
		}
	}
	return false;
}

bool detectIntType(const std::string& str)
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
		{
			std::cout << "NOT INT" << std::endl;
			return false;
		}
	}
	errno = 0;
	long value = std::strtol(str.c_str(), NULL, 10);
	std::cout << "INT_MIN: " << INT_MIN << ". INT_MAX: " << INT_MAX << std::endl;
	if (errno == ERANGE || value < INT_MIN || value > INT_MAX)
	{
		std::cout << "Value out of range" << std::endl;
		return false;
	}
	std::cout << "IS INT" << std::endl;
	return true;
}

bool detectFloatType(const std::string& str)
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
			if(!(isdigit(str[k - 1])) || !(isdigit(str[k +  1]) || str[k + 1] == '+') || str[k + 1] == '-')
				return false;
			count_e++;
		}
	}
	if (count_point > 1 || count_e > 1)
		return false;
	if (count_point == 0 && count_e == 0)
		return false;
	std::cout << "point: " << count_point << ". e: " << count_e << ". str_length: " << str.length() << std::endl;
	for (; i < str.length(); i++)
	{
		unsigned char c = static_cast<unsigned char>(str[i]);

		if (isdigit(c))
			continue;
		if (c == '.' || c == 'e' || c == 'E')
			continue;

		if (c == 'f' && i == str.length() - 1)
			continue;
		std::cout << "Invalid character in number" << std::endl;
		return false;
		/*if (!(c >= '0' && c <= '9') && (count_point > 1 || count_e > 1) && (count_point == 0 && count_e == 0) && str[str.length() - 1] == 'f')
		{
			std::cout << "NOT FLOAT" << std::endl;
			return 1;
		}
		else if (!(c >= '0' && c <= '9') && (count_point > 1 || count_e > 1) && (count_point == 0 && count_e == 0) && str[str.length() - 1] != 'f')
		{
			std::cout << "NOT DOUBLE" << std::endl;
			return 1;
		}*/
	}
	if (str[str.length() - 1] == 'f')
		std::cout << "It is FLOAT" << std::endl;
	else if (str[str.length() - 1] != 'f')
		std::cout << "It is DOUBLE" << std::endl;
	return true;
}

/*bool detectFloatType(const std::string& str)
{
	if (str.empty())
		return false;
	size_t i = 0;
	size_t count_point = 0;
	size_t count_e = 0;
	
	if (str[0] == '+' || str[0] == '-')
		i = 1;

	if (str.length() == i || str[str.length() - 1] != 'f')
		return false;
	for (size_t k = 0; k < str.length() - 1; k++)
	{
		unsigned char d = static_cast<unsigned char>(str[k]);
		if (d == '.')
			count_point++;
		if (d == 'e' || d == 'E')
		{
			if (k == 0)
				return false;
			if (k == str.length() - 2)
				return false;
			count_e++;
		}
	}
	if (count_point > 1 || count_e > 1)
		return false;
	if (count_point == 0 && count_e == 0)
		return false;
	std::cout << "point: " << count_point << ". e: " << count_e << ". str_length: " << str.length() << std::endl;
	for (; i < str.length(); i++)
	{
		unsigned char c = static_cast<unsigned char>(str[i]);
		if (!(c >= '0' && c <= '9') && (count_point > 1 || count_e > 1) && (count_point == 0 && count_e == 0))
		{
			std::cout << "NOT FLOAT" << std::endl;
			return 1;
		}
	}
	std::cout << "It is FLOAT" << std::endl;
	return true;
}*/

bool detectInputType(const std::string& str)
{
	if (detectCharType(str))
		return true;
	if (detectIntType(str))
		return true;
	if (detectFloatType(str))
		return true;
	return false;
}

void ScalarConverter::convert(const std::string& str)
{
	if (handlePseudoLiterals(str))
		return;
	if (handleNonDisplayableCharacters(str))
		return;
	if (detectInputType(str))
		return ;
}
