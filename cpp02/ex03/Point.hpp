/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauldos- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 10:48:15 by pauldos-          #+#    #+#             */
/*   Updated: 2025/06/17 10:33:46 by pauldos-         ###   ########.fr       */
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

	public:
		Point( void ); // Default constructor
		Point( const float n, const float m );
		Point( const Point& other );
		Point& operator=(const Point& other);
		~Point( void );
		
		Fixed getX() const;
		Fixed getY() const;
};

#endif
