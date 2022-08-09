#ifndef POINT_HPP
#define POINT_HPP

#include <iostream>

#include "Fixed.hpp"

class Point {
public:
	Point(void);
	Point(const float x, const float y);
	Point(const Point& p);
	~Point(void);

	Point& operator=(const Point& p);

	const Fixed& getX(void) const;
	const Fixed& getY(void) const;

private:
	Fixed const _x;
	Fixed const _y;
};

bool bsp(const Point& a, const Point& b, const Point& c, const Point& point);
float outer(const Point& p1, const Point& p2, const Point& p3);

#endif