/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauldos- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 10:31:21 by pauldos-          #+#    #+#             */
/*   Updated: 2025/05/19 10:31:29 by pauldos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Point.hpp"

static Fixed area(Point const& p1, Point const& p2, Point const& p3)
{
	//(x1 * (y2 - y3)) + (x2 * (y3 - y1)) + (x3 * (y1 - y2))
	Fixed term1 = p1.getX() * (p2.getY() - p3.getY());
	Fixed term2 = p2.getX() * (p3.getY() - p1.getY());
	Fixed term3 = p3.getX() * (p1.getY() - p2.getY());

	Fixed result = term1 + term2 + term3;

	return result / Fixed(2); // OR: Fixed(0.5f) * result;
}

bool	bsp( Point const a, Point const b, Point const c, Point const point)
{
	Fixed totalArea = area(a, b, c).abs();
	Fixed area1 = area(point, b, c).abs();
	Fixed area2 = area(a, point, c).abs();
	Fixed area3 = area(a, b, point).abs();

	std::cout << "Total: " << totalArea << "\n";
std::cout << "A1: " << area1 << ", A2: " << area2 << ", A3: " << area3 << std::endl;


	//If any of the areas is zero, point is on edge or vertex
	if (area1 == 0 || area2 == 0 || area3 == 0)
		return false;

	// Check if the sum of the small areas is close enough to the total area
	//const Fixed tolerance = Fixed(0.01f); // small tolerance for floating-point comparison
	const Fixed tolerance = Fixed(0.01f); 
	if ((area1 + area2 + area3 - totalArea).abs() < tolerance)
        	return true;
	return false;
}
