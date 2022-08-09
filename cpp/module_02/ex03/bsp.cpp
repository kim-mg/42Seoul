#include "Fixed.hpp"
#include "Point.hpp"

Fixed sign(const Point& p1, const Point& p2, const Point& p3) {
	return (p1.getX() - p3.getX()) * (p2.getY() - p3.getY())
		- (p2.getX() - p3.getX()) * (p1.getY() - p3.getY());
}

bool bsp(const Point& a, const Point& b, const Point& c, const Point& point) {
	Fixed alpha;
	Fixed beta;
	Fixed gamma;

	alpha = sign(point, a, b);
	beta = sign(point, b, c);
	gamma = sign(point, c, a);
	if ((alpha > 0 && beta > 0 && gamma > 0)
		|| (alpha < 0 && beta < 0 && gamma < 0))
		return true;
	return false;
}