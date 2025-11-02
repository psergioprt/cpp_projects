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

    sorter.printVector();
    sorter.fillDeque();

    clock_t start = clock();
    sorter.dequeSortAlgorithm();
    clock_t end = clock();

    sorter.printSortedDeque();

    double elapsed = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1e6;
    std::cout << "Time to process a range of " << argc - 1
              << " elements with std::deque : " << elapsed << " us" << std::endl;
}


/*#include <iostream>
#include <string>

#include "PmergeMe.hpp"

int main(int argc, char *argv[])
{
	if (argc < 2)
		return (std::cout << "Requires two arguments" << std::endl, 1);

	PmergeMe a;
	for (int i = 1; i < argc; i++)
	{
		if (!a.convertStringToInt(argv[i]))
			return 1;
	}
	a.fillDeque();
	a.printVector();
	a.dequeSortAlgorithm();
	return 0;
}*/
