#include "Fixed.hpp"

const int Fixed::_fractional_bits = 8;

std::ostream& operator<<(std::ostream& os, const Fixed& f) {
	return os << f.toFloat();
}

Fixed::Fixed(void) 
	: _fixed_point_value(0) {
}

Fixed::Fixed(const Fixed& fixed) {
	*this = fixed;
}

Fixed::Fixed(const float in)
	: _fixed_point_value(std::roundf(in * (1 << Fixed::_fractional_bits))) {	
}

Fixed::Fixed(const int in)
	: _fixed_point_value(in << Fixed::_fractional_bits) {
}

Fixed::~Fixed(void) {
}

Fixed& Fixed::operator=(const Fixed& fixed) {
	if (this != &fixed)
		_fixed_point_value = fixed.getRawBits();
	return *this;
}

bool Fixed::operator>(const Fixed& f) const {
	return _fixed_point_value > f.getRawBits();
}

bool Fixed::operator<(const Fixed& f) const {
	return _fixed_point_value < f.getRawBits();
}

bool Fixed::operator>=(const Fixed& f) const {
	return _fixed_point_value >= f.getRawBits();
}

bool Fixed::operator<=(const Fixed& f) const {
	return _fixed_point_value <= f.getRawBits();
}

bool Fixed::operator==(const Fixed& f) const {
	return _fixed_point_value == f.getRawBits();
}

bool Fixed::operator!=(const Fixed& f) const {
	return _fixed_point_value != f.getRawBits();
}

Fixed Fixed::operator+(const Fixed& f) const {
	return Fixed(toFloat() + f.toFloat());
}

Fixed Fixed::operator-(const Fixed& f) const {
	return Fixed(toFloat() - f.toFloat());
}

Fixed Fixed::operator*(const Fixed& f) const {
	return Fixed(toFloat() * f.toFloat());
}

Fixed Fixed::operator/(const Fixed& f) const {
	return Fixed(toFloat() / f.toFloat());
}

Fixed& Fixed::operator++(void) {
	++_fixed_point_value;
	return *this;
}

Fixed Fixed::operator++(int) {
	Fixed temp(*this);

	++_fixed_point_value;
	return temp;
}

Fixed& Fixed::operator--(void) {
	--_fixed_point_value;
	return *this;
}

Fixed Fixed::operator-- (int) {
	Fixed temp(*this);

	--_fixed_point_value;
	return temp;
}

int Fixed::getRawBits(void) const {
	return _fixed_point_value;
}

void Fixed::setRawBits(int const raw) {
	_fixed_point_value = raw;
}

float Fixed::toFloat(void) const {
	return static_cast<float>(_fixed_point_value) / (1 << Fixed::_fractional_bits);
}

int Fixed::toInt(void) const {
	return _fixed_point_value >> Fixed::_fractional_bits;
}

Fixed& Fixed::min(Fixed& f1, Fixed& f2) {
	if (f1 < f2)
		return f1;
	return f2;
}

const Fixed& Fixed::min(const Fixed& f1, const Fixed& f2) {
	if (f1 < f2)
		return f1;
	return f2;
}

Fixed& Fixed::max(Fixed& f1, Fixed& f2) {
	if (f1 > f2)
		return f1;
	return f2;
}

const Fixed& Fixed::max(const Fixed& f1, const Fixed& f2) {
	if (f1 > f2)
		return f1;
	return f2;
}
