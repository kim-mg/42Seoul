#ifndef CONVERT_HPP
#define CONVERT_HPP

#include <cstdlib>
#include <cmath>

#include <iostream>
#include <string>
#include <exception>
#include <limits>
#include <iomanip>

class Convert {
private:
	double _value;
	bool _impossible;

	Convert(void);

public:
	explicit Convert(const std::string& input);
	Convert(const Convert& src);
	~Convert(void);

	Convert& operator=(const Convert& src);

	const double& getValue(void) const;
	const bool& getImposs(void) const;

	char toChar(void) const;
	int toInt(void) const;
	float toFloat(void) const;
	double toDouble(void) const;

	void printChar(void) const;
	void printInt(void) const;
	void printFloat(void) const;
	void printDouble(void) const;
	void printAll(void) const;

	class NonDisplayableException : public std::exception {
	public:
		const char* what(void) const throw();
	};

	class ImpossibleException : public std::exception {
	public:
		const char* what(void) const throw();
	};
};

#endif