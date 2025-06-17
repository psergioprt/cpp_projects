/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauldos- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 10:32:25 by pauldos-          #+#    #+#             */
/*   Updated: 2025/06/17 11:18:31 by pauldos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Point.hpp"
#include "Fixed.hpp"

Point::Point() : _x(0), _y(0)
{
//	std::cout << "Default constructor initialized" << std::endl;
}

Point::Point( const float n, const float m) : _x(n), _y(m)
{
//	std::cout << "Floats constructor called" << std::endl;
}

Point::Point(const Point& other): _x(other._x), _y(other._y)
{
//	std::cout << "Copy constructor" << std::endl;
}

Point& Point::operator=(const Point& other)
{
	(void)other;
	// cannot assign to const member (const _x and const _y)
	// so this operator is intentionally left black
	return *this;
}

Fixed Point::getX() const
{
	return this->_x;
}

Fixed Point::getY() const
{
	return this->_y;
}

Point::~Point()
{
//	std::cout << "Destructor called" << std::endl;
}
