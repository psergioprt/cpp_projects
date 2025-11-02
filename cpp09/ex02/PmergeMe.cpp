#include "PmergeMe.hpp"
#include <iostream>
#include <string>
#include <cstdlib>
#include <deque>

PmergeMe::PmergeMe() : _number(0){}

PmergeMe::~PmergeMe(){}

int PmergeMe::convertStringToInt(const std::string& value)
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
	_v.push_back(_number);
	return _number;
}

void PmergeMe::printVector() const
{
	std::cout << "Before: ";
	for (size_t i = 0; i < _v.size(); i++)
		std::cout << _v[i] << " ";
	std::cout << std::endl;
}

void PmergeMe::fillDeque()
{
	_d.assign(_v.begin(), _v.end());
}

void PmergeMe::printSortedDeque() const
{
	std::cout << "After: ";
	for (size_t i = 0; i < _d.size(); i++)
		std::cout << _d[i] << " ";
	std::cout << std::endl;
}

// --------------------------------------------
// Jacobsthal sequence generator
// --------------------------------------------
std::vector<int> PmergeMe::generateJacobsthalSequence(int n)
{
	std::vector<int> seq;
	if (n <= 0)
		return seq;

	seq.push_back(1);
	int j1 = 1, j2 = 3;
	while (j2 < n)
	{
		seq.push_back(j2);
		int next = j2 + 2 * j1;
		j1 = j2;
		j2 = next;
	}
	return seq;
}

// --------------------------------------------
// Compare pairs and separate into max/min
// --------------------------------------------
void PmergeMe::comparePairs(const std::deque<int>& source, std::deque<int>& maxList, std::deque<int>& minList, int& leftover, bool& hasLeftover)
{
	maxList.clear();
	minList.clear();
	hasLeftover = false;

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
		leftover = source.back();
		hasLeftover = true;
	}
}

// --------------------------------------------
// Binary insert helper
// --------------------------------------------
void PmergeMe::binaryInsert(std::deque<int>& mainChain, int value)
{
	std::deque<int>::iterator pos = std::lower_bound(mainChain.begin(), mainChain.end(), value);
	mainChain.insert(pos, value);
}

// --------------------------------------------
// Recursive Ford–Johnson (Merge-Insertion Sort)
// --------------------------------------------
void PmergeMe::fordJohnson(std::deque<int>& arr)
{
	if (arr.size() <= 1)
		return;

	std::deque<int> maxList;
	std::deque<int> minList;
	int leftover = 0;
	bool hasLeftover = false;

	comparePairs(arr, maxList, minList, leftover, hasLeftover);
	static int round = 0;
	++round;
	std::cout << "round " << round << std::endl;
	for (size_t i = 0; i < maxList.size(); i++)
		std::cout << maxList[i] << " ";
	std::cout << std::endl;

	// recursively sort the main chain (maxList)
	fordJohnson(maxList);

	// build result chain starting from sorted maxList
	std::deque<int> result = maxList;
	std::cout << "result: " << std::endl;
	for (size_t i = 0; i < result.size(); i++)
		std::cout << result[i] << " ";
	std::cout << std::endl;

	// Jacobsthal sequence defines insertion order
	std::vector<int> jac = generateJacobsthalSequence(minList.size());

	// insert first min element
	if (!minList.empty())
        	binaryInsert(result, minList[0]);
	
	// insert elements in Jacobsthal order
	for (size_t i = 1; i < jac.size(); ++i)
	{
		int idx = jac[i] - 1;
		if (idx < (int)minList.size())
			binaryInsert(result, minList[idx]);
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
            	binaryInsert(result, minList[i]);
	}

	if (hasLeftover)
        	binaryInsert(result, leftover);

	arr = result;
}

void PmergeMe::dequeSortAlgorithm()
{
	if (_d.empty())
		return;

	fordJohnson(_d);
}
