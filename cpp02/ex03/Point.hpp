#ifndef POINT_HPP
#define POINT_HPP

#include <iostream>

class Point
{
	private:
		const Fixed	x;
		const Fixed	y;
		// Anything else usefull

	public:
		Point( void ); // Default constructor
		Point( const float n, const float m ); // Constructor takes 2 const float
		Point( const Point& other ); // Copy constructor
		Point &operator=(const Point& other); // Copy assignment operator overload
		~Point( void ); // Destructor
}

#endif
