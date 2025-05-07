/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauldos- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 15:34:03 by pauldos-          #+#    #+#             */
/*   Updated: 2025/05/07 15:50:25 by pauldos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class	Fixed
{
	private:
		int	_fixedPointValue;
		static const int	_fractionalBits = 8;

	public:
		Fixed( void ); // Default constructor
		Fixed(const Fixed& other); //Copy constructor
		Fixed& operator=(const Fixed& other); //Copy assignement operator
		
		~Fixed( void ); // Destructor
		int	getRawBits( void ) const;
		void	setRawBits( int const raw );
};

#endif
