#include "RPN.hpp"
#include <iostream>
#include <string>
#include <cstdlib>

RPN::RPN() : _error(false){}

RPN::~RPN(){}

RPN::RPN(const RPN& other)
{
	_stack = other._stack;
	_error = other._error;
}

RPN& RPN::operator=(const RPN& other)
{
	if (this != &other)
	{
		_stack = other._stack;
		_error = other._error;
	}
	return *this;
}

void RPN::printToken()
{
	if (_error || _stack.size() != 1)
		std::cerr << "Error" << std::endl;
	else
		std::cout << _stack.top() << std::endl;
}

void RPN::splitToken(const std::string value)
{
	size_t pos = 0;
	size_t nextSpace;
	std::string token;

	for(size_t i = 0; i < value.size(); i++)
	{
		if (!isdigit(value[i]) && value[i] != '+' && value[i] != '-' && value[i] != '*' && value[i] != '/' && value[i] != ' ')
		{ _error = true; return; }
		if (i != 0)
		{
			if (value[i] != ' ' && value[i - 1] != ' ')
			{ _error = true; return; }
		}
	}
	while (pos < value.size())
	{
		nextSpace = value.find(' ', pos);
		if (nextSpace == std::string::npos)
		{
			token = value.substr(pos);
			if (!token.empty())
				processToken(token);
			break;
		}
		else
		{
			token = value.substr(pos, nextSpace - pos);
			if (!token.empty())
				processToken(token);
			pos = nextSpace + 1;
		}
	}
}

void RPN::processToken(const std::string token)
{
	if (token.size() == 1 && isdigit(token[0]))
	{

		int digit = token[0] - '0';
		_stack.push(digit);
	}
	else if (token == "+" || token == "-" || token == "*" || token == "/")
	{
		if (_stack.size() < 2)
		{ _error = true; return; }
		int num2 = _stack.top();
		_stack.pop();
		int num1 = _stack.top();
		_stack.pop();
		int result = 0;
		if (token == "+")
			result = num1 + num2;
		else if (token == "-")
			result = num1 - num2;
		else if (token == "*")
			result = num1 * num2;
		else if (token == "/")
		{
			if (num2 == 0)
			{ _error = true; return; }
			result = num1 / num2;
		}
		else
		{ _error = true; return; }
		_stack.push(result);
	}
}
