/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauldos- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 17:58:07 by pauldos-          #+#    #+#             */
/*   Updated: 2025/11/04 16:57:20 by pauldos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <fstream>
#include <iostream>
#include <cstdlib>

BitcoinExchange::BitcoinExchange(){}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
	_exchangeRates = other._exchangeRates;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange &other)
{
	if (this != &other)
	{
		_exchangeRates = other._exchangeRates;
	}
	return *this;
}

BitcoinExchange::~BitcoinExchange(){}

std::string BitcoinExchange::myTrim(const std::string &s) const
{
	size_t start = 0;
	size_t end = s.length();

	while (start < end && std::isspace(static_cast<unsigned char>(s[start])))
		start++;
	while (end > start && std::isspace(static_cast<unsigned char>(s[end - 1])))
		end--;
	return s.substr(start, end - start);
}

bool BitcoinExchange::dateFormatChecker(const std::string& date) const
{
	if (date.size() != 10 || date[4] != '-' || date[7] != '-')
		return false;
	std::string year = date.substr(0, 4);
	std::string month = date.substr(5, 2);
	std::string day = date.substr(8, 2);
	if (year.size() != 4 || month.size() != 2 || day.size() != 2)
		return false;
	for (size_t i = 0; i < year.size(); i++)
	{
		if (!isdigit(year[i]))
			return false;
	}
	for (size_t i = 0; i < month.size(); i++)
	{
		if (!isdigit(month[i]))
			return false;
	}
	for (size_t i = 0; i < day.size(); i++)
	{
		if (!isdigit(day[i]))
			return false;
	}
	int m = std::atoi(month.c_str());
	int d = std::atoi(day.c_str());
	if (m < 1 || m > 12 || d < 1 || d > 31)
		return false;
	return true;
}

bool BitcoinExchange::valueChecker(const std::string& num) const
{
	if (num.empty())
		return false;
	bool isDecimal = false;
	if (num[0] == '.' || num[num.size() - 1] == '.')
		return false;
	for (size_t i = 0; i < num.size(); i++)
	{
		if (!isdigit(num[i]) && num[i] != '.' && num[0] != '-')
			return false;
		if (num[i] == '.')
		{
			if (isDecimal)
				return false;
			isDecimal = true;
		}
	}
	return true;
}

void BitcoinExchange::openExchangeRateFile(std::string exchangeRateFile)
{
	std::ifstream file(exchangeRateFile.c_str());
	if (!file.is_open())
	{
		std::cerr << "Error: could not open exchange rate file" << std::endl;
		return;
	}
	std::string line;
	std::getline(file, line);
	while (std::getline(file, line))
	{
		if (line.empty())
		{
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}
		size_t pos = line.find(',');
		if (pos == std::string::npos)
		{
			std::cerr << "Error: bad csv format => " << line << std::endl;
			continue;
		}
		std::string date = myTrim(line.substr(0, pos));
		std::string rateStr = myTrim(line.substr(pos + 1));
		if (!dateFormatChecker(date))
		{
			std::cerr << "Error: bad exchange date format  => " << date << std::endl;
			continue;
		}
		if (!valueChecker(rateStr))
		{
			std::cerr << "Error: bad exchange Bitcoin rate format => " << rateStr << std::endl;
			continue;
		}
		double rate = std::atof(rateStr.c_str());
		_exchangeRates[date] = rate;
	}
}

double BitcoinExchange::getRateForDate(const std::string &date) const
{
	std::map<std::string, double>::const_iterator it = _exchangeRates.lower_bound(date);
	if (it == _exchangeRates.end() || it->first != date)
	{
		if (it == _exchangeRates.begin())
			return 0;
		--it;
	}
	return it->second;
}

void BitcoinExchange::openFileToEvaluate(std::string fileToEvaluate)
{
	std::ifstream file(fileToEvaluate.c_str());
	if (!file.is_open())
	{
		std::cerr << "Error: could not open input file => " << fileToEvaluate << std::endl;
		return;
	}
	
	std::string line;
	std::getline(file, line);
	while (std::getline(file, line))
	{
		if (line.empty())
		{
			std::cerr << "Error: bad input " << line << std::endl;
			continue;
		}
		size_t pos = line.find('|');
		if (pos == std::string::npos)
		{
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}
		std::string date = myTrim(line.substr(0, pos));
		std::string val = myTrim(line.substr(pos + 1));
		if (!dateFormatChecker(date))
		{
			std::cerr << "Error: bad input => " << date << std::endl;
			continue;
		}
		if (!valueChecker(val))
		{
			std::cerr << "Error: bad input => " << val << std::endl;
			continue;
		}
		double value = std::atof(val.c_str());
		if (value < 0)
		{
			std::cerr << "Error: not a positive number." << std::endl;
			continue;

		}
		if (value > 1000)
		{
			std::cerr << "Error: too large a number." << std::endl;
			continue;
		}

		double rate = getRateForDate(date);
		double result = value * rate;
		std::cout << date << " => " << value << " = " << result << std::endl; 
	}
}
