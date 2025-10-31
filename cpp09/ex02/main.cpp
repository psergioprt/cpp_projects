#include "PmergeMe.hpp"
#include <iostream>

int main(int argc, char *argv[])
{
	if (argc != 2)
		return (std::cout << "Requires two arguments", 1);
	PmergeMe a;
	a.convert_value(argv[1]);
	a.print_value();
	return 0;	
}
