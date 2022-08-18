#ifndef CONVERT_HPP
#define CONVERT_HPP

#include <cstdlib>

#include <iostream>
#include <string>
#include <exception>

class Convert {
private:
	std::string _value;

	Convert(void);

public:
	explicit Convert(const std::string& value);
	Convert(const Convert& src);
	~Convert(void);

	Convert& operator=(const Convert& src);

	const std::string& getValue(void) const;

	const char& toChar(void);
	const int& toInt(void);
	const float& toFloat(void);
	const double& toDouble(void);

	void print(void) const;

	// class NonDisplayableException : public std::exception {
	// public:
	// 	const char* what(void) const throw();
	// };

	// class ImpossibleException : public std::exception {
	// public:
	// 	const char* what(void) const throw();
	// };
};

#endif