/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauldos- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 11:26:22 by pauldos-          #+#    #+#             */
/*   Updated: 2025/10/02 08:44:31 by pauldos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Array.hpp"

template<typename T>
unsigned int Array<T>::size() const
{
	return _size;
}

int main()
{
	Array<char> y(5);
	y[0] = 'H';
	y[1] = 'i';
	y[2] = '4';
	y[3] = '2';
	y[4] = '!';

	int len = y.size();

	for (int i = 0; i < len; i++)
		std::cout << y[i];
	std::cout << std::endl;

	Array<int> a(5);
	std::cout << "size: " << a.size() << std::endl;

	a[0] = 20;
	a[1] = 30;
	std::cout << "a[0] -> " << a[0] << ". a[1] -> " << a[1] << std::endl;

	const Array<int> f = a;
	std::cout << f[1] << std::endl;


	std::cout << "f[0] -> " << f[0] << ". f[1] -> " << f[1] << std::endl;

	int *b = new int();
	std::cout << b << std::endl;
	delete b;

	Array<int> c(a);
	Array<int> d = a;

	Array<int> e;
	e = a;
	try
	{
		Array<int> x(5);
		std::cout << "size: " << a.size() << std::endl;

		x[0] = 20;
		x[5] = 30;
		std::cout << "x[0] -> " << x[0] << ". x[1] -> " << x[1] << std::endl;
	}
	catch (const Array<int>::OutOfBoundsException& e)
	{
		std::cerr << "Caught Array exception: " << e.what() << std::endl;
	}
	return 0;
}
