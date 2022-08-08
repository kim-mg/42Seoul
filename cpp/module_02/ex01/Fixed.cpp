#include "Fixed.hpp"

const int Fixed::_fractional_bits = 8;

std::ostream& operator<<(std::ostream& os, const Fixed& f) {
	return os << f.toFloat();
}

Fixed::Fixed(void) 
	: _fixed_point_value(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& fixed) {
	std::cout << "Copy constructor called" << std::endl;
	*this = fixed;
}

Fixed::Fixed(const float in)
	: _fixed_point_value(std::roundf(in * (1 << Fixed::_fractional_bits))) {	
	std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const int in)
	: _fixed_point_value(in << Fixed::_fractional_bits) {
	std::cout << "Int constructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& fixed) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &fixed)
		_fixed_point_value = fixed.getRawBits();
	return *this;
}

Fixed::~Fixed(void) {
	std::cout << "Destructor called" << std::endl;
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
