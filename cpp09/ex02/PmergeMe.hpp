/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauldos- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 17:20:07 by pauldos-          #+#    #+#             */
/*   Updated: 2025/11/06 17:20:10 by pauldos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		
		PmergeMe(const PmergeMe& other);
		PmergeMe& operator=(const PmergeMe& other);
		
		//Container independent, works for both Vector or Deque
		std::vector<int> makeJacobIndicesV(int n);
		std::deque<int>makeJacobIndicesD(int n);

		//For Deque container
		void comparePairs(const std::deque<int>& source, std::deque<int>& maxList, std::deque<int>& minList, int& unpairedValue, bool& hasUnpairedValue);
		void insertSorted(std::deque<int>& mainChain, int value);
		void fordJohnson(std::deque<int>& arr);

		//For Vector container
		void comparePairs(const std::vector<int>& source, std::vector<int>& maxList, std::vector<int>& minList, int& unpairedValue, bool& hasUnpairedValue);
		void insertSorted(std::vector<int>& mainChain, int value);
		void fordJohnson(std::vector<int>& arr);


	public:
		PmergeMe();
		~PmergeMe();

		bool convertStringToInt(const std::string& value);
		void printContainer() const;
		bool  check_duplicates() const;
		void startSortCheckTimePrintouts(int value);
		
		//Deque
		void fillDeque();
		void dequeSortAlgorithm();
		void printSortedDeque() const;
		
		//Vector
		void vectorSortAlgorithm();
		void printSortedVector() const;
};

#endif
