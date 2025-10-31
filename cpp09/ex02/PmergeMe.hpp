#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <string>

class PmergeMe
{
	private:
		int _value;
	public:
		PmergeMe();
		~PmergeMe();

		void print_value();
		int convert_value(const std::string& value);

};

#endif
