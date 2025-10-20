/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauldos- <pauldos-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 13:35:53 by pauldos-          #+#    #+#             */
/*   Updated: 2025/10/20 15:55:25 by pauldos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "MutantStack.hpp"
#include <list>

int main()
{
	{
		MutantStack<int>
		mstack;
		mstack.push(5);
		mstack.push(17);
		std::cout << mstack.top() << std::endl;
		mstack.pop();
		std::cout << mstack.size() << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		//[...]
		mstack.push(0);
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::stack<int> s(mstack);
	}

	std::cout << "\nUsing List" << std::endl;
	{
		std::list<int>mlist;
		mlist.push_back(5);
		mlist.push_back(17);
		std::cout << mlist.back() << std::endl;
		mlist.pop_back();
		std::cout << mlist.size() << std::endl;
		mlist.push_back(3);
		mlist.push_back(5);
		mlist.push_back(737);
		//[...]
		mlist.push_back(0);
		std::list<int>::iterator it = mlist.begin();
		std::list<int>::iterator ite = mlist.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
	}
	std::cout << "\nCopy Constructor and Copy Assignement Operator" << std::endl;
	{
		MutantStack<float> st;
		st.push(12.6);
		st.push(3.4);
		st.push(10.7);
		
		MutantStack<float> copyConst(st);
		MutantStack<float> assignOperator;

		assignOperator = st;

		std::cout << "Original stack (st) top value: " << st.top() << std::endl;
		std::cout << "Copy constructor (copyConst) top value: " << copyConst.top() << std::endl;
		std::cout << "Assignement Operator top value: " << assignOperator.top() << std::endl;
		
		st.pop();
		std::cout << "Original stack (st) top value: " << st.top() << std::endl;
		std::cout << "Copy constructor (copyConst) top value: " << copyConst.top() << std::endl;
		std::cout << "Assignement Operator top value: " << assignOperator.top() << std::endl;

		
	}
	std::cout << "\nEmpty stack check" << std::endl;
	{
		MutantStack<int> st;
		std::cout << st.size() << std::endl;
		for (int i = 0; i < 5; i++)
			st.push(i);
		std::cout << st.size() << std::endl;
		for (int i = 0; i < 5; i++)
			st.pop();
		std::cout << st.size() << std::endl;
	}
	return 0;
}
