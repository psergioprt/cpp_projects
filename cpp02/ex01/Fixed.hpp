/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauldos- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 15:45:02 by pauldos-          #+#    #+#             */
/*   Updated: 2025/05/09 15:45:05 by pauldos-         ###   ########.fr       */
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
		Fixed( void ); // default constructor
		Fixed( const int n); // NEW: from int
		Fixed( const float n); // NEW: from float
		Fixed(const Fixed& other); // Copy constructor
		Fixed& operator=(const Fixed& other); // Copy assignment operator
		~Fixed ( void ); // Destructor

		int	getRawBits( void )const;
		void	setRawBits( int const raw );

		float	toFloat( void ) const; //NEW: fixed -> float
		int	toInt( void ) const; //NEW: fixed -> int
};

// NEW: operator<< overload
std::ostream& operator<<(std::ostream& out, const Fixed& fixed);

#endif
