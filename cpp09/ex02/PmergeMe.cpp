#include "PmergeMe.hpp"
#include <iostream>
#include <string>
#include <cstdlib>

PmergeMe::PmergeMe() : _value(0){}

PmergeMe::~PmergeMe(){}

void PmergeMe::print_value()
{
	std::cout << "Value is: " << _value << std::endl;
}

int PmergeMe::convert_value(const std::string& value)
{
	int val = atoi(value.c_str());
	_value = val;
	return val;
}
