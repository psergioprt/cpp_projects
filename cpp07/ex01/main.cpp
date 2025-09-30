/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauldos- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 15:00:11 by pauldos-          #+#    #+#             */
/*   Updated: 2025/09/30 16:40:15 by pauldos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include "iter.hpp"
#include <iostream>
#include <cstring>

/*void increment_by_3(int &nb)
{
	 nb += 3;
}*/

void increment_by_3(int nb[])
{

	 nb += 3;
}

void to_lower(char &nb)
{
	if (nb >= 65 && nb <= 90)
		nb += 32;
}

int main()
{
	int arr[] = {1, 2, 3, 4, 5};
	size_t len = sizeof(arr) / sizeof(arr[0]);	
	iter(arr, len, print_element);
	
	std::string arr2[] = {"Hello", "World"};
	len = sizeof(arr2) / sizeof(arr2[0]);
	iter(arr2, len, print_element);

	int arr3[] = {1, 2, 3, 4, 5};
	len = sizeof(arr3) / sizeof(arr3[0]);
	iter(arr3, len, increment_by_3);
	for (int i = 0; i < 5; i++)
		std::cout << arr3[i] << std::endl;

	char arr4[] = "Hello";
	iter(arr4, strlen(arr4), to_lower);
	std::cout << arr4 << std::endl;

	return 0;
}
