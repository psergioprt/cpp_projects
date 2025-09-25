/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauldos- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 16:23:14 by pauldos-          #+#    #+#             */
/*   Updated: 2025/09/25 16:59:09 by pauldos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Whatever.hpp"

int main()
{
	int x = 10;
	int y = 15;
	int z = 15;

	float a = 7.8;
	float b = 9.4;
	
	std::cout << "min of x and y is: " << ::min(x, y) << std::endl;
	std::cout << "max of x and y is: " << ::max(x, y) << std::endl;
	std::cout << "max of y and z is: " << ::max(x, z) << std::endl;
	std::cout << "min of a and b is: " << ::min(a, b) << std::endl;
	std::cout << "max of a and b is: " << ::max(a, b) << std::endl;

	::swap(x, y);
	std::cout << "x: " << x << ". y: " << y << std::endl;

	::swap(a, b);
	std::cout << "a: " << a << ". b: " << b << std::endl;


	return 0;
}
