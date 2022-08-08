#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {
public:
	Fixed(void);
	Fixed(const Fixed& fixed);
	Fixed(const int in);
	Fixed(const float in);
	Fixed& operator=(const Fixed& fixed);
	~Fixed(void);
	
	int getRawBits(void) const;
	void setRawBits(int const raw);

	float toFloat(void) const;
	int toInt(void) const;

private:
	int _fixed_point_value;
	static const int _fractional_bits;
};

std::ostream& operator<<(std::ostream& os, const Fixed& f);

#endif