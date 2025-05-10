/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauldos- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 11:43:03 by pauldos-          #+#    #+#             */
/*   Updated: 2025/05/10 11:16:09 by pauldos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
	private:
		int	_fixedPointValue;
		static const int	_fractionalBits = 8;
	public:
		Fixed( void ); // Default constructor
		Fixed( const int n); // from int
		Fixed( const float n); // from float
		Fixed( const Fixed& other); // Copy constructor
		Fixed& operator = (const Fixed& other); // Copy assignement operator
		~Fixed( void ); // Destructor
				
		int	getRawBits( void );
		void	setRawBits( int const raw);

		float	toFloat( void ) const; // float converter
		int	toInt( void ) const; // int converter

		// Comparison operators
		bool	operator>(const Fixed& other) const;
		bool	operator<(const Fixed& other) const;
		bool	operator>=(const Fixed& other) const;
		bool	operator<=(const Fixed& other) const;
		bool	operator==(const Fixed& other) const;
		bool	operator!=(const Fixed& other) const;
		
		// Arithmetic operators
		Fixed	operator+(const Fixed& other) const;
		Fixed	operator-(const Fixed& other) const;
		Fixed	operator*(const Fixed& other) const;
		Fixed	operator/(const Fixed& other) const;

		Fixed& operator++(); // Pre-increment operator
		Fixed& operator--(); // Pre-decrement operator
		Fixed operator++(int); // Post-increment operator
		Fixed operator--(int); // Post-decrement operator
		
		// Min functions
		static Fixed& min(Fixed& a, Fixed& b);
		static const Fixed& min(const Fixed& a, const Fixed& b);

		// Max functions
		static Fixed& max(Fixed& a, Fixed& b);
		static const Fixed& max(const Fixed& a, const Fixed& b);
};

//operator<<overload
std::ostream& operator<<(std::ostream& out, const Fixed& fixed);

#endif
