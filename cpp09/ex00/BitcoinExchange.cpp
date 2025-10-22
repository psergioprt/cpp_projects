#include "BitcoinExchange.hpp"
#include <fstream>
#include <iostream>

BitcoinExchange::BitcoinExchange() : _value(0){}
BitcoinExchange::BitcoinExchange(const int value) : _value(value){}
BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) : _value(other._value){}
BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
	if (this != &other)
	{
		_value = other._value;
	}
	return *this;
}
BitcoinExchange::~BitcoinExchange(){}

int BitcoinExchange::output() const
{
	return _value;
}

int BitcoinExchange::multiply_by_rate() const
{
	return _value * 2;
}

void BitcoinExchange::open_file() const
{
	std::ifstream file("data.csv");
	if (!file.is_open())
	{
		std::cerr << "Error reading file" << std::endl;
	}
	
	int count_line = 0;
	std::string line;
	while (std::getline(file, line))
		count_line++;
	std::cout << "lines in data.csv file: " << count_line << std::endl;
}
