/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauldos- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 10:48:18 by pauldos-          #+#    #+#             */
/*   Updated: 2025/10/02 12:31:02 by pauldos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include "easyfind.hpp"

int main()
{
	int arr[] = {1, 2, 3, 4, 5};
	std::vector<int> vect(arr, arr + 5);
	try
	{
		std::vector<int>::iterator it = easyfind(vect, 5);
		std::cout << "Found: " << *it << std::endl;
	}catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	std::vector<int> vect2;
	for (int i = 6; i < 20; i++)
		vect2.push_back(i);
	try
	{
		std::cout << "vect2 size is: " << vect2.size() << std::endl;
		std::vector<int>::iterator it2 = easyfind(vect2, 19);
		std::cout << "Found: " << *it2 << std::endl;
		std::vector<int>::iterator it3 = easyfind(vect2, 20);
		std::cout << "Found: " << *it3 << std::endl;
	}catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	vect2.pop_back();
	try
	{
		std::cout << "vect2 size is: " << vect2.size() << std::endl;
		std::vector<int>::iterator it2 = easyfind(vect2, 19);
		std::cout << "Found: " << *it2 << std::endl;
		std::vector<int>::iterator it3 = easyfind(vect2, 20);
		std::cout << "Found: " << *it3 << std::endl;
	}catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	std::vector<char> vect3;
	vect3.push_back('H');
	vect3.push_back('i');
	vect3.push_back('4');
	vect3.push_back('2');
	vect3.push_back('!');

	char letter = 'H';
	try
	{
		std::vector<char>::iterator it4 = easyfind(vect3, letter);
		std::cout << "Found " << *it4 << std::endl;
	}catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	return 0;
}

