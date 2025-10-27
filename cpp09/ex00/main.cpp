#include "BitcoinExchange.hpp"
#include <iostream>
#include <string>

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cerr << "Usage: ./btc csvfile.csv" << std::endl;
		return 1;
	}
	BitcoinExchange b(5);
	std::cout << b.output() << std::endl;
	std::cout << b.multiply_by_rate() << std::endl;
	

	BitcoinExchange c;
	std::string fileToEvaluate = argv[1];
	std::string exchangeRateFile = "data.csv";
	c.openExchangeRateFile(exchangeRateFile);
	c.openFileToEvaluate(fileToEvaluate);
	return 0;
}
