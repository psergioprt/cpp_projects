/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauldos- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 11:26:22 by pauldos-          #+#    #+#             */
/*   Updated: 2025/10/01 12:09:36 by pauldos-         ###   ########.fr       */
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

	int *b = new int();
	std::cout << b << std::endl;
	delete b;

	return 0;
}
