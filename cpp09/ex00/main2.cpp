#include <iostream>
#include "BitcoinExchangeTemplate.hpp"

int main()
{

	int num1 = 5;
	int num2 = 5;

	::swap(num1, num2);
	BitcoinET <int>b1(num1);
	std::cout << b1.print() << std::endl;

	std::cout << "bigger number is: " << bigger(num1, num2) << std::endl;
	std::cout << "lower number is: " << lower(num1, num2) << std::endl;

	return 0;
}
