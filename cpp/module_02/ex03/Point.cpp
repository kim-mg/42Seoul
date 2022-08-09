#include "Fixed.hpp"
#include "Point.hpp"

Point::Point(void)
	: _x(0), _y(0) {
}

Point::Point(const float x, const float y)
	: _x(x), _y(y) {
}

Point::Point(const Point& p)
	: _x(p._x), _y(p._y) {	
}

Point::~Point(void) {
}

Point& Point::operator=(const Point& p) {
	if (this != &p) {
		const_cast<Fixed&>(_x) = p.getX();
		const_cast<Fixed&>(_y) = p.getY();
	}
	return *this;
}

const Fixed& Point::getX(void) const {
	return _x;
}

const Fixed& Point::getY(void) const {
	return _y;
}
