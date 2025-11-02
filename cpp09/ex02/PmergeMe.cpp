#include "PmergeMe.hpp"
#include <iostream>
#include <string>
#include <cstdlib>
#include <deque>

PmergeMe::PmergeMe() : _number(0){}

PmergeMe::~PmergeMe(){}

void PmergeMe::printValue() const
{
	std::cout << "Number => " << _number << std::endl;
}

int PmergeMe::convertStringToInt(const std::string& value)
{
	_number = atoi(value.c_str());
	_v.push_back(_number);
	return _number;
}

void PmergeMe::printVector() const
{
	for (size_t i = 0; i < _v.size(); i++)
		std::cout << _v[i] << " ";
	std::cout << std::endl;
	/*std::cout << "v_length => " << _v.size() << std::endl;
	std::cout << "v front => " << _v.front() << std::endl;
	std::cout << "v back => " << _v.back() << std::endl;*/
}

void PmergeMe::fillDeque()
{
	_d.assign(_v.begin(), _v.end());
}

void PmergeMe::dequeSortAlgorithm()
{
	std::deque<int> max;
	std::deque<int> min;
	int first;
	int second;
	if (_d.empty())
		return (void)(std::cout << "list is empty" << std::endl);
	if (_d.size() == 1)
	{
		std::cout << _d.front() << std::endl;
		std::cout << "has only one value" << std::endl;
		return;
	}
	size_t len = _d.size() / 2;
	bool odd = false;
	if (_d.size() % 2 != 0)
		odd = true;
	for (size_t i = 0; i < len; i++)
	{
		first = _d.front();
		_d.pop_front();
		second = _d.front();
		_d.pop_front();
		compareAndPush(first, second, max, min);
	}
	if (odd)
	{
		max.push_back(_d.front());
		_d.pop_front();
	}
	for (size_t i = 0; i < max.size(); i++)
		std::cout << "max[" << i << "] => " << max[i] << std::endl;
	for (size_t i = 0; i < min.size(); i++)
		std::cout << "min[" << i << "] => " << min[i] << std::endl;
	recursiveSort(max);
}



void PmergeMe::compareAndPush(int first, int second, std::deque<int>& max, std::deque<int>& min)
{
		if (first > second)
		{
			max.push_back(first);
			min.push_back(second);
		}
		else
		{
			max.push_back(second);
			min.push_back(first);
		}
		std::cout << "first: " << first << std::endl;
		std::cout << "second: " << second << std::endl;
}

void PmergeMe::recursiveSort(std::deque<int>& d)
{
	if (d.size() <= 1)
		return;
	
	std::deque<int>max;
	std::deque<int>min;
	
	
	int first;
	int second;
	size_t len = d.size() / 2;
	bool odd = false;
	if (d.size() % 2 != 0)
		odd = true;
	for (size_t i = 0; i < len; i++)
	{
		first = d.front();
		d.pop_front();
		second = d.front();
		d.pop_front();
		compareAndPush(first, second, max, min);
	}
	if (odd)
	{
		max.push_back(d.front());
		d.pop_front();
	}
	if (!d.empty())
	{
		max.push_back(d.front());
		d.pop_front();
	}
	recursiveSort(max);

	d.clear();

	for (size_t i = 0; i < max.size(); i++)
		d.push_back(max[i]);

	for (size_t i = 0; i < min.size(); i++)
		d.push_back(min[i]);
	for (size_t i = 0; i < d.size(); i++)
		std::cout << d[i] << " ";
	std::cout << std::endl;
}
