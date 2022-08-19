#include "Convert.hpp"

Convert::Convert(void) : _input() {
}

Convert::Convert(const std::string& input) : _input(input) {
	_value = std::strtod(input.c_str(), NULL);
}

Convert::Convert(const Convert& src) {
	_input = src.getInput();		
}

Convert::~Convert(void) {
}

Convert& Convert::operator=(const Convert& src) {
	if (this != &src)
		_input = src.getInput();
	return *this;
}

const std::string& Convert::getInput(void) const {
	return _input;
}

// const char& Convert::toChar(void) {
// 	return std::strtoi(_input.c_str());
// }

// const int& Convert::toInt(void) {
// 	return std::strtoi(_input.c_str());
// }

float Convert::toFloat(void) const {
	return static_cast<float>(std::strtof(_input.c_str(), NULL));
}

double Convert::toDouble(void) const {
	return static_cast<double>(std::strtod(_input.c_str(), NULL));
}

void Convert::print(void) const {
	// std::cout << "char: " << toChar() << std::endl
		// << "int: " << toInt() << std::endl
	std::cout
		<< "float: " << toFloat() << std::endl
		<< "double: " << toDouble() << std::endl;
}
