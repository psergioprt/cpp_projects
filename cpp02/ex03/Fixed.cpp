/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauldos- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 10:31:43 by pauldos-          #+#    #+#             */
/*   Updated: 2025/06/17 10:32:06 by pauldos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed()
{
//	std::cout << "Default constructor called" << std::endl;
	this->_fixedPointValue = 0;
}

Fixed::Fixed(const int n)
{
//	std::cout << "Int constructor called" << std::endl;
	this->_fixedPointValue = n << this->_fractionalBits;
}

Fixed::Fixed(const float n)
{
//	std::cout << "Float constructor called" << std::endl;
	this->_fixedPointValue = roundf(n * (1 << this->_fractionalBits));
}

Fixed::Fixed(const Fixed& other)
{
	this->_fixedPointValue = other._fixedPointValue;	
}

Fixed& Fixed::operator=(const Fixed& other)
{
	if (this != &other)
		this->_fixedPointValue = other._fixedPointValue;
	return *this;
}

Fixed::~Fixed()
{
//	std::cout << "Destructor called" << std::endl;
}

int	Fixed::getRawBits() const
{
//	std::cout << "getRawBits member function called" << std::endl;
	return this->_fixedPointValue;
}

void	Fixed::setRawBits(int const raw)
{
//	std::cout << "setRawBits member function called" << std::endl;
	this->_fixedPointValue = raw;
}

float	Fixed::toFloat() const
{
	return static_cast<float>(this->_fixedPointValue) / (1 << this->_fractionalBits);
}

int	Fixed::toInt() const
{
	return this->_fixedPointValue >> this->_fractionalBits;
}

std::ostream& operator<<(std::ostream& out, const Fixed& fixed)
{
	out << fixed.toFloat();
	return out;
}

bool	Fixed::operator>(const Fixed& other) const
{
	return this->_fixedPointValue > other._fixedPointValue;
}

bool	Fixed::operator<(const Fixed& other) const
{
	return this->_fixedPointValue < other._fixedPointValue;
}

bool	Fixed::operator>=(const Fixed& other) const
{
	return this->_fixedPointValue >= other._fixedPointValue;
}

bool	Fixed::operator<=(const Fixed& other) const
{
	return this->_fixedPointValue <= other._fixedPointValue;
}

bool	Fixed::operator==(const Fixed& other) const
{
	return this->_fixedPointValue == other._fixedPointValue;
}

bool	Fixed::operator!=(const Fixed& other) const
{
	return this->_fixedPointValue != other._fixedPointValue;
}

Fixed Fixed::operator+(const Fixed& other) const
{
	Fixed	result;
	result.setRawBits(this->_fixedPointValue + other._fixedPointValue);
	return result;
}

Fixed Fixed::operator-(const Fixed& other) const
{
	Fixed	result;
	result.setRawBits(this->_fixedPointValue - other._fixedPointValue);
	return result;
}

Fixed Fixed::operator*(const Fixed& other) const
{
	Fixed	result;
	result.setRawBits((this->_fixedPointValue * other._fixedPointValue) >> this->_fractionalBits);
	return result;
}

Fixed Fixed::operator/(const Fixed& other) const
{
	Fixed	result;
	result.setRawBits((this->_fixedPointValue << this->_fractionalBits) / other._fixedPointValue);
	return result;
}

Fixed& Fixed::operator++()
{
	++this->_fixedPointValue;
	return *this;
}

Fixed& Fixed::operator--()
{
	--this->_fixedPointValue;
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed temp = *this;
	++this->_fixedPointValue;
	return temp;
}

Fixed Fixed::operator--(int)
{
	Fixed temp = *this;
	++this->_fixedPointValue;
	return temp;
}

Fixed& Fixed::min(Fixed& a, Fixed& b)
{
	if (a < b)
		return a;
	else
		return b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
	if (a < b)
		return a;
	else
		return b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
	if (a > b)
		return a;
	else
		return b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
	if (a > b)
		return a;
	else
		return b;
}

Fixed Fixed::abs() const
{
	if (toFloat() < 0)
		return Fixed(-toFloat());
	return *this;
}
