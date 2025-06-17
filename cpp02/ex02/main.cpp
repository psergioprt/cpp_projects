/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauldos- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 15:29:27 by pauldos-          #+#    #+#             */
/*   Updated: 2025/06/16 23:18:25 by pauldos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

int main( void )
{
	Fixed		a;
	Fixed const	b( Fixed( 5.05f ) * Fixed( 2 ) );
	Fixed		c( Fixed( 10 ) );
	
	std::cout << "Check 'a' values before and after incremements" << std::endl;
	std::cout << "----------------------------------------------" << std::endl;
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << ++c << std::endl;
	std::cout << c << std::endl;
	
	std::cout << "Check max and min 'a' values before and after incremements" << std::endl;
	std::cout << "----------------------------------------------------------" << std::endl;
	std::cout << "a: " << a << std::endl;
	std::cout << "b: " << b << std::endl;
	std::cout << "max: " << Fixed::max( a, b ) << std::endl;
	std::cout << "min: " << Fixed::min( a, b ) << std::endl;
	
	std::cout << "Arithmetic operations" << std::endl;
	std::cout << "---------------------" << std::endl;
	std::cout << "a + b: " << a + b << std::endl;
	std::cout << "b - a: " << b - a << std::endl;
	std::cout << "a * b: " << a * b << std::endl;
	std::cout << "b / a: " << b / a << std::endl;
	
	std::cout << "Debugging Raw numbers outputs" << std::endl;
	std::cout << "-----------------------------" << std::endl;
	std::cout << "Raw a: " << a.getRawBits() << std::endl;
	std::cout << "Raw b: " << b.getRawBits() << std::endl;
	
	std::cout << "Comparing operators" << std::endl;
	std::cout << "-------------------" << std::endl;
	std::cout << "a > b: " << (a > b) << std::endl;
	std::cout << "a < b: " << (a < b) << std::endl;
	std::cout << "a >= b: " << (a >= b) << std::endl;
	std::cout << "a <= b: " << (a <= b) << std::endl;
	std::cout << "a == b: " << (a == b) << std::endl;

	return 0;
}
