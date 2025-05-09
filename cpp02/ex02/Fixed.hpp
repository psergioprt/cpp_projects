/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauldos- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 11:43:03 by pauldos-          #+#    #+#             */
/*   Updated: 2025/05/09 12:02:34 by pauldos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
	private:
		int	fixedPointValue;
		static const int	fractionalBits = 8;
	public:
		Fixed( void ); // Default constructor
		Fixed( const Fixed& other); //Copy constructor

		~Fixed( void ); // Destructor

};

#endif
