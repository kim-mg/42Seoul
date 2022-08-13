#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void)
	: _type("WrongAnimal") {
	std::cout << GREEN << _type << NORMAL << " made by Default Constructor"
		<< std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& src)
	: _type(src.getType()) {
	std::cout << GREEN << _type << NORMAL << " made by Copy Constructor"
		<< std::endl;
}

WrongAnimal::~WrongAnimal(void) {
	std::cout << RED << "WrongAnimal" << NORMAL << " Dead..." << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& src) {
	std::cout << GREEN << src.getType() << NORMAL << " made by Assignment Operator"
		<< std::endl;
	if (this != &src) {
		_type = src.getType();
	}
	return *this;
}

void WrongAnimal::setType(const std::string& type) {
	_type = type;
}

std::string WrongAnimal::getType(void) const {
	return _type;
}

void WrongAnimal::makeSound(void) const {
	std::cout << "Ani! Ani! Mal! Mal!" << std::endl;
}
