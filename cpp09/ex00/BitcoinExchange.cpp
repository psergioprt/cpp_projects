#include "BitcoinExchange.hpp"
#include <fstream>
#include <iostream>
#include <cstdlib>

BitcoinExchange::BitcoinExchange() : _value(0){}
BitcoinExchange::BitcoinExchange(const double value) : _value(value){}
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

double BitcoinExchange::output() const
{
	return _value;
}

double BitcoinExchange::multiply_by_rate() const
{
	return _value * 2;
}

void BitcoinExchange::openExchangeRateFile(std::string exchangeRateFile) const
{
	std::ifstream file(exchangeRateFile.c_str());
	if (!file.is_open())
	{
		std::cerr << "Error reading file" << std::endl;
		return;
	}
	int count_line = 0;
	std::string line;
	std::getline(file, line);
	while (std::getline(file, line))
	{
		size_t pos = line.find(',');
		if (pos == std::string::npos)
		{
			std::cerr << "Not a valid csv file" << std::endl;
			return;
		}
		if (line.empty())
		{
			std::cerr << "Line is empty" << std::endl;
			return;
		}
		std::string left = line.substr(0, pos);
		std::string right = line.substr(pos + 1);
		if (left.empty() || right.empty())
		{
			std::cerr << "Either date or value is empty!" << std::endl;
			return;
		}

		while (left[0] == ' ')
			left.erase(0, 1);
		while (left[left.size() - 1] == ' ')
			left.erase(left.size() - 1);
		while (right[0] == ' ')
			right.erase(0, 1);
		while (right[right.size() - 1] == ' ')
			right.erase(right.size() - 1);
		count_line++;

		if (count_line < 5)
			std::cout << "Left: " << left << " | Right: " << right << std::endl;
	}
	std::cout << "Exchange Rate lines count: " << count_line << std::endl;

}

void BitcoinExchange::openFileToEvaluate(std::string fileToEvaluate) const
{
	std::ifstream file(fileToEvaluate.c_str());
	if (!file.is_open())
	{
		std::cerr << "Error reading file" << std::endl;
		return;
	}
	
	int count_line = 0;
	std::string line;
	while (std::getline(file, line))
	{
		size_t pos = line.find('|');
		if (pos == std::string::npos)
		{
			std::cerr << "Not a valid csv file" << std::endl;
			return ;
		}
		if (line.empty())
		{
			std::cerr << "Line is empty" << std::endl;
			return;
		}
		std::string left = line.substr(0, pos);
		std::string right = line.substr(pos + 1);
		if (left.empty() || right.empty())
		{
			std::cerr << "Either date or value is empty!" << std::endl;
			return;
		}
		while (left[0] == ' ')
			left.erase(0, 1);
		while (left[left.size() - 1] == ' ')
			left.erase(left.size() - 1);
		while (right[0] == ' ')
			right.erase(0, 1);
		while (right[right.size() - 1] == ' ')
			right.erase(right.size() - 1);
		double value = std::atof(right.c_str());
		if (value < 0 || value > 1000)
		{
			std::cerr << right << " is out of bounds value. Cannot be lower than 0 and higher than 1000" << std::endl;
			continue;

		}
		std::cout << "Left: " << left << " | Right: " << right << std::endl;

		count_line++;
	}
	std::cout << "lines in data.csv file: " << count_line << std::endl;
}
