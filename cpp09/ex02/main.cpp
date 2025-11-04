#include "PmergeMe.hpp"
#include <iostream>

int main(int argc, char* argv[])
{
	if (argc < 2)
	{
		std::cerr << "Error: provide numbers as arguments." << std::endl;
		return 1;
	}
	PmergeMe sorter;

	for (int i = 1; i < argc; ++i)
	{
		if (!sorter.convertStringToInt(argv[i]))
			return 1;
	}
	sorter.printContainer();
	sorter.fillDeque();

	sorter.startSortCheckTimePrintouts(argc - 1);
	return 0;
}
