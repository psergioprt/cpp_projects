/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauldos- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 10:33:11 by pauldos-          #+#    #+#             */
/*   Updated: 2025/06/17 15:17:38 by pauldos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Point.hpp"

std::string	bsp( Point const a, Point const b, Point const c, Point const point);

int	main()
{
	Point	a(0, 0);
	Point	b(10, 0);
	Point	c(0, 10);

	Point inside(2, 2);
	Point onEdge(0, 5);
	Point outside(10, 10);

	std::cout << "Inside? " << bsp(a, b, c, inside) << std::endl;
	std::cout << "On edge? " << bsp(a, b, c, onEdge) << std::endl;
	std::cout << "Outside? " << bsp(a, b, c, outside) << std::endl;
}
