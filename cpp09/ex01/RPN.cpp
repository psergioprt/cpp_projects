#include "RPN.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>

RPN::RPN(){}

RPN::~RPN(){}

void RPN::pushValues(const std::string value)
{
	bool isDigit = true;
	for (size_t i = 0; i < value.size(); i++)
	{
		if (!isdigit(value[i]))
		{
			std::cerr << "Not a digit: " << value << std::endl;
			isDigit = false;
			return;
		}
	}
	if (isDigit)
	{
		int convertedValue = std::atoi(value.c_str());
		_stack.push(convertedValue);
	}
}

void RPN::printValues()
{
	while (_stack.size())
	{
		std::cout << _stack.top() << std::endl;
		_stack.pop();
	}
}
