#include "PmergeMe.hpp"
#include <iostream>
#include <string>
#include <cstdlib>
#include <deque>
#include <algorithm>

PmergeMe::PmergeMe() : _number(0){}

PmergeMe::~PmergeMe(){}

//Support Functions

bool PmergeMe::convertStringToInt(const std::string& value)
{
	for (size_t i = 0; i < value.size(); i++)
	{
		if (!isdigit(value[i]))
		{
			std::cout << "Error: Not a digit!" << std::endl;
			return 0;
		}
	}
	_number = atoi(value.c_str());

	if (std::find(_v.begin(), _v.end(), _number) != _v.end())
	{
		std::cerr << "Error: Duplicate number " << _number << "!" << std::endl;
		return false;
	}
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

// Jacobsthal sequence generator works for both vector and deque
//J0 = 0, J1 = 1
//Jn = Jn-1 + 2 * Jn-2, for n >= 2

std::vector<int> PmergeMe::makeJacobIndices(int n)
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
	std::vector<int> jac = makeJacobIndices(minList.size());
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

	// recursively sort the main chain (maxList)
	fordJohnson(maxList);

	// build result chain starting from sorted maxList
	std::vector<int> result = maxList;

	// Jacobsthal sequence defines insertion order
	std::vector<int> jac = makeJacobIndices(minList.size());

	// insert first min element
	if (!minList.empty())
        	insertSorted(result, minList[0]);
	
	// insert elements in Jacobsthal order
	for (size_t i = 1; i < jac.size(); ++i)
	{
		int idx = jac[i] - 1;
		if (idx < (int)minList.size())
			insertSorted(result, minList[idx]);
	}

	// insert any remaining min elements not covered by Jacobsthal
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
