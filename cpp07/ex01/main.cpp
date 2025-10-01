/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauldos- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 15:00:11 by pauldos-          #+#    #+#             */
/*   Updated: 2025/10/01 08:05:51 by pauldos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include "iter.hpp"
#include <iostream>
#include <cstring>

void increment_by_3(int &nb)
{
	nb += 3;
}

template <typename T>
void add_3(T &nb)
{
	nb += 3;
}

void to_lower(char &nb)
{
	if (nb >= 65 && nb <= 90)
		nb += 32;
}

template <typename T>
void print_element(T const& x)
{
	std::cout << x << std::endl;
}

class

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

	std::cout << "\nCHAR ARRAY" << std::endl;
	char arr4[] = "Hello";
	iter(arr4, strlen(arr4), to_lower);
	std::cout << arr4 << std::endl;

	return 0;
}
