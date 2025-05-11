/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauldos- <pauldos-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 17:31:48 by pauldos-          #+#    #+#             */
/*   Updated: 2025/05/10 23:16:23 by pauldos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point
{
	private:
		const Fixed	_x;
		const Fixed	_y;
		// Anything else usefull

	public:
		Point( void ); // Default constructor
		Point( const float n, const float m ); // Constructor takes 2 const float
		Point( const Point& other ); // Copy constructor
		Point& operator=(const Point& other); // Copy assignment operator overload
		~Point( void ); // Destructor
		
		Fixed getX() const;
		Fixed getY() const;
};

#endif
