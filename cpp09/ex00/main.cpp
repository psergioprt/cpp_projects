#include "BitcoinExchange.hpp"
#include <iostream>
#include <string>

int main()
{
	BitcoinExchange b(5);
	std::cout << b.output() << std::endl;
	std::cout << b.multiply_by_rate() << std::endl;

	BitcoinExchange c;

	c.open_file();
	return 0;
}
