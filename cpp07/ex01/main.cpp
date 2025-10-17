/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauldos- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 15:00:11 by pauldos-          #+#    #+#             */
/*   Updated: 2025/10/17 11:29:59 by pauldos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include "iter.hpp"
#include <iostream>
#include <cstring>
#include <cctype>

void increment_by_3(int &nb)
{
	nb += 3;
}

void fincrement_by_3(float &nb)
{
	nb += 3;
}

template <typename T>
void add_3(T &nb)
{
	nb += 3;
}

void to_lower(char &c)
{
	unsigned char uc = static_cast<unsigned char>(c);
	if (std::isupper(uc))
		c = static_cast<char>(std::tolower(uc));
}

template <typename T>
void print_element(T const& x)
{
	std::cout << x << std::endl;
}

int main()
{
	std::cout << "\nCONST INT ARRAY" << std::endl;
	const int carr[] = {1, 2, 3, 4, 5};
	size_t len = sizeof(carr) / sizeof(carr[0]);
	iter(carr, len, print_element);

	std::cout << "\nNON-CONST INT ARRAY" << std::endl;
	int arr[] = {1, 2, 3, 4, 5};
	len = sizeof(arr) / sizeof(arr[0]);	
	iter(arr, len, print_element);
	
	std::cout << "\nSTRING ARRAY" << std::endl;
	std::string arr2[] = {"Hello", "World"};
	len = sizeof(arr2) / sizeof(arr2[0]);
	iter(arr2, len, print_element);

	std::cout << "\nINT ARRAY UPDATING ELEMENTS +3" << std::endl;
	int arr3[] = {1, 2, 3, 4, 5};
	len = sizeof(arr3) / sizeof(arr3[0]);
	iter(arr3, len, increment_by_3);
	iter(arr3, len, print_element);
	
	std::cout << "\nUSING TEMPLATE FUNCTION INT ARRAY UPDATE +3" << std::endl;
	iter(arr3, len, add_3);
	iter(arr3, len, print_element);

	std::cout << "\nFLOAT UPDATING ELEMENTS +3" << std::endl;
	float arr4[] = {1.4, 6.3, 188.9, 3.1415, 0.01};
	len = sizeof(arr4) / sizeof(arr4[0]);
	iter(arr4, len, fincrement_by_3);
	iter(arr4, len, print_element);
	
	std::cout << "\nUSING TEMPLATE FUNCTION FLOAT ARRAY UPDATE +3" << std::endl;
	iter(arr4, len, add_3);
	iter(arr4, len, print_element);


	std::cout << "\nCHAR ARRAY" << std::endl;
	char arr5[] = "HeLlO";
	iter(arr5, strlen(arr5), to_lower);
	std::cout << "Print the string directly" << std::endl;
	std::cout << arr5 << std::endl;
	std::cout << "Print the string using iter function" << std::endl;
	iter(arr5, strlen(arr5), print_element);

	return 0;
}
