#include "PmergeMe.hpp"
#include <iostream>
#include <string>
#include <cstdlib>
#include <deque>
#include <algorithm>
#include <iomanip>


PmergeMe::PmergeMe() : _number(0){}

PmergeMe::~PmergeMe(){}

//Support Functions

bool PmergeMe::check_duplicates() const
{
	if (std::find(_v.begin(), _v.end(), _number) != _v.end())
	{
		std::cerr << "Error: Duplicate number " << _number << "!" << std::endl;
		return false;
	}
	return true;
}

bool PmergeMe::convertStringToInt(const std::string& value)
{
	for (size_t i = 0; i < value.size(); i++)
	{
		if (!isdigit(value[i]))
		{
			std::cout << "Error: Not a valid positive digit!" << std::endl;
			return 0;
		}
	}
	_number = atoi(value.c_str());
	check_duplicates();
	_v.push_back(_number);
	return true;
}

void PmergeMe::printContainer() const
{
	std::cout << "Before: ";
	for (size_t i = 0; i < _v.size(); i++)
		std::cout << _v[i] << " ";
	std::cout << std::endl;
}

void PmergeMe::startSortCheckTimePrintouts(int value)
{
	//deque time
	clock_t start_d = clock();
	dequeSortAlgorithm();
	clock_t end_d = clock();

	//vector time
	clock_t start_v = clock();
	vectorSortAlgorithm();
	clock_t end_v = clock();
	
/*	std::cout << "Print sorted Deque" << std::endl;
	printSortedDeque();
	std::cout << "Print sorted Vector" << std::endl;
*/	printSortedVector();

	double elapsed_d = static_cast<double>(end_d - start_d) / CLOCKS_PER_SEC * 1e2;
	std::cout << std::fixed << std::setprecision(5);
	std::cout << "Time to process a range of " << value << " elements with std::deque : " << elapsed_d << " us" << std::endl;

	double elapsed_v = static_cast<double>(end_v - start_v) / CLOCKS_PER_SEC * 1e2;
	std::cout << "Time to process a range of " << value << " elements with std::vector : " << elapsed_v << " us" << std::endl;


}

void PmergeMe::printSortedDeque() const
{
	std::cout << "After: ";
	for (size_t i = 0; i < _d.size(); i++)
		std::cout << _d[i] << " ";
	std::cout << std::endl;
}

void PmergeMe::printSortedVector() const
{
	std::cout << "After: ";
	for (size_t i = 0; i < _v.size(); i++)
		std::cout << _v[i] << " ";
	std::cout << std::endl;
}

/*Jacobsthal sequence generator works for both vector and deque
J0 = 0, J1 = 1
Jn = Jn-1 + 2 * Jn-2, for n >= 2

J1 = 1, J2 = 3
next = 3 + 2 * 1 = 5
J1 = J2 = 3
J2 = next = 5

next = 5 + 2 * 3 = 11
j1 = 5
j2 = 11*/




std::deque<int> PmergeMe::makeJacobIndicesD(int n)
{
	std::deque<int> ind;
	if (n <= 0)
		return ind;

	ind.push_back(1);
	int j1 = 1, j2 = 3;
	while (j2 < n)
	{
		ind.push_back(j2);
		int next = j2 + 2 * j1;
		j1 = j2;
		j2 = next;
	}
	return ind;
}

//Deque container Functions

void PmergeMe::fillDeque()
{
	_d.assign(_v.begin(), _v.end());
}

void PmergeMe::comparePairs(const std::deque<int>& source, std::deque<int>& maxList, std::deque<int>& minList, int& unpairedValue, bool& hasUnpairedValue)
{
	maxList.clear();
	minList.clear();
	hasUnpairedValue = false;

	size_t len = source.size() / 2;
	bool odd = (source.size() % 2 != 0);
	std::deque<int>::const_iterator it = source.begin();

	for (size_t i = 0; i < len; ++i)
	{
		int first = *it++;
		int second = *it++;
		if (first > second)
		{
			maxList.push_back(first);
			minList.push_back(second);
		}
		else
		{
			maxList.push_back(second);
			minList.push_back(first);
		}
	}
	if (odd)
	{
		unpairedValue = source.back();
		hasUnpairedValue = true;
	}
}

void PmergeMe::insertSorted(std::deque<int>& mainChain, int value)
{
	std::deque<int>::iterator pos = std::lower_bound(mainChain.begin(), mainChain.end(), value);
	mainChain.insert(pos, value);
}

void PmergeMe::fordJohnson(std::deque<int>& arr)
{
	if (arr.size() <= 1)
		return;

	std::deque<int> maxList;
	std::deque<int> minList;
	int unpairedValue = 0;
	bool hasUnpairedValue = false;

	comparePairs(arr, maxList, minList, unpairedValue, hasUnpairedValue);
	fordJohnson(maxList);
	std::deque<int> result = maxList;
	std::deque<int> jac = makeJacobIndicesD(minList.size());
	if (!minList.empty())
        	insertSorted(result, minList[0]);
	for (size_t i = 1; i < jac.size(); ++i)
	{
		int idx = jac[i] - 1;
		if (idx < (int)minList.size())
			insertSorted(result, minList[idx]);
	}
	for (size_t i = 0; i < minList.size(); ++i)
	{
		bool used = false;
		for (size_t j = 0; j < jac.size(); ++j)
		{
			if ((int)jac[j] - 1 == (int)i)
			{
				used = true;
				break;
			}
		}
        	if (!used)
            	insertSorted(result, minList[i]);
	}
	if (hasUnpairedValue)
        	insertSorted(result, unpairedValue);
	arr = result;
}

void PmergeMe::dequeSortAlgorithm()
{
	if (_d.empty())
		return;
	fordJohnson(_d);
}

//Vector container Functions

std::vector<int> PmergeMe::makeJacobIndicesV(int n)
{
	std::vector<int> ind;
	if (n <= 0)
		return ind;

	ind.push_back(1);
	int j1 = 1, j2 = 3;
	while (j2 < n)
	{
		ind.push_back(j2);
		int next = j2 + 2 * j1;
		j1 = j2;
		j2 = next;
	}
	return ind;
}

void PmergeMe::comparePairs(const std::vector<int>& source, std::vector<int>& maxList, std::vector<int>& minList, int& unpairedValue, bool& hasUnpairedValue)
{
	maxList.clear();
	minList.clear();
	hasUnpairedValue = false;

	size_t len = source.size() / 2;
	bool odd = (source.size() % 2 != 0);
	std::vector<int>::const_iterator it = source.begin();

	for (size_t i = 0; i < len; ++i)
	{
		int first = *it++;
		int second = *it++;
		if (first > second)
		{
			maxList.push_back(first);
			minList.push_back(second);
		}
		else
		{
			maxList.push_back(second);
			minList.push_back(first);
		}
	}
	if (odd)
	{
		unpairedValue = source.back();
		hasUnpairedValue = true;
	}
}

void PmergeMe::insertSorted(std::vector<int>& mainChain, int value)
{
	std::vector<int>::iterator pos = std::lower_bound(mainChain.begin(), mainChain.end(), value);
	mainChain.insert(pos, value);
}

void PmergeMe::fordJohnson(std::vector<int>& arr)
{
	if (arr.size() <= 1)
		return;

	std::vector<int> maxList;
	std::vector<int> minList;
	int unpairedValue = 0;
	bool hasUnpairedValue = false;

	comparePairs(arr, maxList, minList, unpairedValue, hasUnpairedValue);

	fordJohnson(maxList);

	std::vector<int> result = maxList;

	std::vector<int> jac = makeJacobIndicesV(minList.size());

	if (!minList.empty())
        	insertSorted(result, minList[0]);
	
	for (size_t i = 1; i < jac.size(); ++i)
	{
		int idx = jac[i] - 1;
		if (idx < (int)minList.size())
			insertSorted(result, minList[idx]);
	}

	for (size_t i = 0; i < minList.size(); ++i)
	{
		bool used = false;
		for (size_t j = 0; j < jac.size(); ++j)
		{
			if ((int)jac[j] - 1 == (int)i)
			{
				used = true;
				break;
			}
		}
        	if (!used)
            	insertSorted(result, minList[i]);
	}

	if (hasUnpairedValue)
        	insertSorted(result, unpairedValue);

	arr = result;
}

void PmergeMe::vectorSortAlgorithm()
{
	if (_v.empty())
		return;
	fordJohnson(_v);
}
