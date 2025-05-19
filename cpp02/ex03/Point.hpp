/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauldos- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 10:48:15 by pauldos-          #+#    #+#             */
/*   Updated: 2025/05/19 10:48:20 by pauldos-         ###   ########.fr       */
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
