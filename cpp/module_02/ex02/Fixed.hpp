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
	~Fixed(void);

	Fixed& operator=(const Fixed& fixed);

	bool operator>(const Fixed& f) const;
	bool operator<(const Fixed& f) const;
	bool operator>=(const Fixed& f) const;
	bool operator<=(const Fixed& f) const; 
	bool operator==(const Fixed& f) const;
	bool operator!=(const Fixed& f) const;

	Fixed operator+(const Fixed& f) const;
	Fixed operator-(const Fixed& f) const;
	Fixed operator*(const Fixed& f) const;
	Fixed operator/(const Fixed& f) const;

	Fixed& operator++(void);
	Fixed operator++(int);
	Fixed& operator--(void);
	Fixed operator-- (int);
	
	int getRawBits(void) const;
	void setRawBits(int const raw);
	float toFloat(void) const;
	int toInt(void) const;

	static Fixed& min(Fixed& f1, Fixed& f2);
	static const Fixed& min(const Fixed& f1, const Fixed& f2);
	static Fixed& max(Fixed& f1, Fixed& f2);
	static const Fixed& max(const Fixed& f1, const Fixed& f2);

private:
	int _fixed_point_value;
	static const int _fractional_bits;
};

std::ostream& operator<<(std::ostream& os, const Fixed& f);

#endif