#include "Animal.hpp"
#include "Dog.hpp"

Dog::Dog(void) {
	_type = D_TYPE;
	std::cout << GREEN << _type << NORMAL << " made by Default Constructor"
		<< std::endl;
}

Dog::Dog(const Dog& src) {
	std::cout << GREEN << src.getType() << NORMAL << " made by Copy Constructor"
		<< std::endl;
	_type = src.getType();
}

Dog::~Dog(void) {
	std::cout << RED << _type << NORMAL << "Dead..." << std::endl;
}

Dog& Dog::operator=(const Dog& src) {
	std::cout << GREEN << src.getType() << NORMAL << " made by Assignment Operator"
		<< std::endl;
	if (this != &src) {
		_type = src.getType();
	}
	return *this;
}

void Dog::makeSound(void) const {
	std::cout << D_SOUND << std::endl;
}
