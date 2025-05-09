/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauldos- <pauldos-@student.42.porto.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 18:56:36 by pauldos-          #+#    #+#             */
/*   Updated: 2025/05/08 20:42:04 by pauldos-         ###   ########.fr       */
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
		Fixed( const int ); // NEW: from int
		Fixed( const float ); // NEW: from float
		Fixed(const Fixed& other); // Copy constructor
		Fixed& operator=(const Fixed& other); // Copy assignment operator
		~Fixed ( void ); // Destructor

		int	getRawBits( void )const;
		void	setRawBits( int const raw );

		float	toFloat( void ) const; //NEW: fixed -> float
		int	toInt( void ) const; //NEW: fixed -> int
					     
		// NEW: operator<< overload
		std::ostream& operator<<(std::ostream& out, const Fixed& fixed);
};

#endif
