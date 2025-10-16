/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauldos- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 15:00:11 by pauldos-          #+#    #+#             */
/*   Updated: 2025/10/16 17:46:45 by pauldos-         ###   ########.fr       */
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

class Element
{
	private:
		int n;
	public:
		Element(int n = 0) : n(n){}
		int get() const
		{
			return n;
		}
		void add3()
		{
			n += 3;
		}
};

std::ostream &operator<<(std::ostream &out, Element const &a)
{
	out << a.get();
	return out;
}

void element_add3(Element &a)
{
	a.add3();
}

void element_print(Element const &a)
{
	std::cout << a << std::endl;
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

	std::cout << "\nCHAR ARRAY" << std::endl;
	char arr4[] = "HeLlO";
	iter(arr4, strlen(arr4), to_lower);
	std::cout << "Print the string directly" << std::endl;
	std::cout << arr4 << std::endl;
	std::cout << "Print the string using iter function" << std::endl;
	iter(arr4, strlen(arr4), print_element);

	std::cout << "\nCLASS TYPE ARRAY (custom type element) UPDATED(+3)" << std::endl;
	Element aarr[] = { Element(-3), Element(0), Element(3)};
	len = sizeof(aarr) / sizeof(aarr[0]);
	iter(aarr, len, element_add3);
	iter(aarr, len, element_print);

	return 0;
}
