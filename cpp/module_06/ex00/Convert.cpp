#include "Convert.hpp"

Convert::Convert(void) : _value(), _impossible(false) {
}

Convert::Convert(const std::string& input)
	: _value(0), _impossible(false) {
	char* end_ptr = NULL;
	_value = std::strtod(input.c_str(), &end_ptr);
	if (_value == 0.0 && (input[0] != '-' && input[0] != '+' && !std::isdigit(input[0])))
		_impossible = true;
	if (*end_ptr && std::strcmp(end_ptr, "f"))
		_impossible = true;
}

Convert::Convert(const Convert& src) {
	_value = src.getValue();
	_impossible = src.getImposs();
}

Convert::~Convert(void) {
}

Convert& Convert::operator=(const Convert& src) {
	if (this != &src) {
		_value = src.getValue();
		_impossible = src.getImposs();
	}
	return *this;
}

const double& Convert::getValue(void) const {
	return _value;
}

const bool& Convert::getImposs(void) const {
	return _impossible;
}

char Convert::toChar(void) const {
	return static_cast<char>(_value);
}

int Convert::toInt(void) const {
	return static_cast<int>(_value);
}

float Convert::toFloat(void) const {
	return static_cast<float>(_value);
}

double Convert::toDouble(void) const {
	return static_cast<double>(_value);
}

void Convert::printChar(void) const {
	try {
		if (_impossible || _value < 0 || 255 < _value
			|| std::isnan(_value))
			throw ImpossibleException();
		if (_value < 32 || 126 < _value)
			throw NonDisplayableException();
		std::cout << "char: "
			<< "'" << toChar() << "'" << std::endl;
	} catch (std::exception& e) {
		std::cout << "char: "
			<< e.what() << std::endl;
	}
}

void Convert::printInt(void) const {
	try {
		if (_impossible || _value < -2147483648 || 2147483647 < _value
			|| std::isnan(_value))
			throw ImpossibleException();
		std::cout << "int: "
			<< toInt() << std::endl;
	} catch (std::exception& e) {
		std::cout << "int: "
			<< e.what() << std::endl;
	}
}

void Convert::printFloat(void) const {
	try {
		if (_impossible)
			throw ImpossibleException();
		if (!std::isnan(_value) && !std::isinf(_value)
			&& std::roundf(_value) == _value) {
			std::cout << "float: "
				<< std::setprecision(std::numeric_limits<float>::digits10)
				<< toFloat() << ".0f" << std::endl;
		} else {
			std::cout << "float: "
				<< (std::isinf(_value) ? std::showpos : std::noshowpos)
				<< std::setprecision(std::numeric_limits<float>::digits10)
				<< toFloat() << "f" << std::endl;
		}
	} catch (std::exception& e) {
		std::cout << "float: "
			<< e.what() << std::endl;
	}
}

void Convert::printDouble(void) const {
	try {
		if (_impossible)
			throw ImpossibleException();
		if (!std::isnan(_value) && !std::isinf(_value)
			&& std::round(toDouble()) == toDouble()) {
			std::cout << "double: "
				<< std::setprecision(std::numeric_limits<double>::digits10)
				<< toDouble() << ".0" << std::endl;
		} else {
			std::cout << "double: "
				<< (std::isinf(_value) ? std::showpos : std::noshowpos)
				<< std::setprecision(std::numeric_limits<double>::digits10)
				<< toDouble() << std::endl;
		}
	} catch (std::exception& e) {
		std::cout << "double: "
			<< e.what() << std::endl;
	}
}

void Convert::printAll(void) const {
	printChar();
	printInt();
	printFloat();
	printDouble();
}

const char* Convert::NonDisplayableException::what(void) const throw() {
	return "Non displayable";
}

const char* Convert::ImpossibleException::what(void) const throw() {
	return "impossible";
}
