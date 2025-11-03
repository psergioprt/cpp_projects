#include "PmergeMe.hpp"
#include <iostream>
#include <ctime>

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
	
	clock_t start = clock();
	sorter.dequeSortAlgorithm();
	clock_t end = clock();

	clock_t start_v = clock();
	sorter.vectorSortAlgorithm();
	clock_t end_v = clock();

	std::cout << "Print sorted Deque" << std::endl;
	sorter.printSortedDeque();

	std::cout << "Print sorted Vector" << std::endl;
	sorter.printSortedVector();

	double elapsed = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1e1;
	std::cout << "Time to process a range of " << argc - 1 << " elements with std::deque : " << elapsed << " us" << std::endl;
	
	double elapsed_v = static_cast<double>(end_v - start_v) / CLOCKS_PER_SEC * 1e1;
	std::cout << "Time to process a range of " << argc - 1 << " elements with std::vector : " << elapsed_v << " us" << std::endl;
}
