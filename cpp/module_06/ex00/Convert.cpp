#include "Convert.hpp"

Convert::Convert(void) : _value() {
}

Convert::Convert(const std::string& value) : _value(value) {
}

Convert::Convert(const Convert& src) {
	_value = src.getValue();		
}

Convert::~Convert(void) {
}

Convert& Convert::operator=(const Convert& src) {
	if (this != &src)
		_value = src.getValue();
	return *this;
}

const std::string& Convert::getValue(void) const {
	return _value;
}

const char& Convert::toChar(void) {
	return std::atoi(_value.c_str());
}

const int& Convert::toInt(void) {
	return std::atoi(_value.c_str());
}

const float& Convert::toFloat(void) {
	return std::atof(_value.c_str());
}

const double& Convert::toDouble(void) {
	return std::atod(_value.c_str());
}

void Convert::print(void) const {
	std::cout << "char: " << toChar() << std::endl
		<< "int: " << toInt() << std::endl
		<< "float: " << toFloat() << std::endl
		<< "double: " << toDouble() << std::endl;
}
