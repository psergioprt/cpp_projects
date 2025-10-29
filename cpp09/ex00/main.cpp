#include "BitcoinExchange.hpp"
#include <iostream>
#include <string>

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cerr << "Error: could not open file" << std::endl;
		return 1;
	}
	BitcoinExchange c;
	std::string fileToEvaluate = argv[1];
	std::string exchangeRateFile = "data.csv";
	c.openExchangeRateFile(exchangeRateFile);
	c.openFileToEvaluate(fileToEvaluate);
	return 0;
}
