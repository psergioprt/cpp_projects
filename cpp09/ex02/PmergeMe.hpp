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

		std::vector<int> generateJacobsthalSequence(int n);

		void comparePairs(const std::deque<int>& source, std::deque<int>& maxList, std::deque<int>& minList, int& leftover, bool& hasLeftover);
		void binaryInsert(std::deque<int>& mainChain, int value);
		void fordJohnson(std::deque<int>& arr);

	public:
		PmergeMe();
		~PmergeMe();
	
		int convertStringToInt(const std::string& value);
		
		//Deque
		void fillDeque();
		void printSortedDeque() const;
		void dequeSortAlgorithm();
		//void compareAndPush(int first, int second, std::deque<int>& max, std::deque<int>& min);
		//void recursiveSortDeque(std::deque<int>& d);
		//void insertInOrderDeque(std::deque<int>& d, int value);
		

		//Vector

		void printValue() const;
	
		void printVector() const;
};

#endif
