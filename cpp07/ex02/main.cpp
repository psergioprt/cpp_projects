/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauldos- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 11:26:22 by pauldos-          #+#    #+#             */
/*   Updated: 2025/10/01 17:19:08 by pauldos-         ###   ########.fr       */
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
	Array<int> a(5);
	std::cout << "size: " << a.size() << std::endl;

	a[0] = 20;
	a[1] = 30;

	const Array<int> f(2);
	f[0] = 50;
	f[1] = 80;


	std::cout << "a[0] -> " << a[0] << ". a[1] -> " << a[1] << std::endl;
	std::cout << "f[0] -> " << f[0] << ". f[1] -> " << f[1] << std::endl;

	int *b = new int();
	std::cout << b << std::endl;
	delete b;

	Array<int> c(a);
	Array<int> d = a;

	Array<int> e;
	e = a;


	return 0;
}
