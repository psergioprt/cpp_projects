/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauldos- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 11:26:22 by pauldos-          #+#    #+#             */
/*   Updated: 2025/10/17 19:33:55 by pauldos-         ###   ########.fr       */
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

	Array<int> c(a);
	Array<int> d = a;
	std::cout << "c[0] -> " << c[0] << ". d[0] -> " << d[0] << std::endl;

	a[0] = 456;
	std::cout << "c[0] -> " << c[0] << ". d[0] -> " << d[0] << std::endl;
	std::cout << "a[0] -> " << a[0] << ". a[1] -> " << a[1] << std::endl;

	Array<int> e;
	e = a;
	try
	{
		Array<int> x(5);
		std::cout << "size: " << a.size() << std::endl;

		x[0] = 20;
		x[4] = 30;
		std::cout << "x[0] -> " << x[0] << ". x[1] -> " << x[1] << std::endl;
	}
	catch (const Array<int>::OutOfBoundsException& e)
	{
		std::cerr << "Caught Array exception: " << e.what() << std::endl;
	}
	return 0;
}
