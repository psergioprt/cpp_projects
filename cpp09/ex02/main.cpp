#include <iostream>
#include <string>

#include "PmergeMe.hpp"

int main(int argc, char *argv[])
{
	if (argc < 2)
		return (std::cout << "Requires two arguments" << std::endl, 1);

	PmergeMe a;
	for (int i = 1; i < argc; i++)
	{
		a.convertStringToInt(argv[i]);
	//	a.printValue();
	}
	a.fillDeque();
	a.printVector();
	a.dequeSortAlgorithm();
	return 0;
}
