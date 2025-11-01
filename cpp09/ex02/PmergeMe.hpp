#include <string>
#include <vector>
#include <deque>

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

class PmergeMe
{
	private:
		int _number;
		std::vector<int> _v;
		std::deque<int> _d;

	public:
		PmergeMe();
		~PmergeMe();

		void printValue() const;
		int convertStringToInt(const std::string& value);
		void printVector() const;
		void fillDeque();
		void dequeSortAlgorithm();
		void compareAndPush(int first, int second, std::deque<int>& max, std::deque<int>& min);
		void recursiveSortAlgorithm(std::deque<int>& d);
};

#endif
