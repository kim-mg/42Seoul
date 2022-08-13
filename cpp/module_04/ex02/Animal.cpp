#include "Animal.hpp"

Animal::Animal(void)
	: _type("Animal") {
	std::cout << GREEN << _type << NORMAL << " made by Default Constructor"
		<< std::endl;
}

Animal::Animal(const Animal& src)
	: _type(src.getType()) {
	std::cout << GREEN << _type << NORMAL << " made by Copy Constructor"
		<< std::endl;
}

Animal::~Animal(void) {
	std::cout << RED << "Animal" << NORMAL << " Dead..." << std::endl;
}

Animal& Animal::operator=(const Animal& src) {
	std::cout << GREEN << src.getType() << NORMAL << " made by Assignment Operator"
		<< std::endl;
	if (this != &src) {
		_type = src.getType();
	}
	return *this;
}

void Animal::setType(const std::string& type) {
	_type = type;
}

std::string Animal::getType(void) const {
	return _type;
}
