#include "Animal.hpp"
#include "Cat.hpp"

Cat::Cat(void) {
	_type = WC_TYPE;
	std::cout << GREEN << _type << NORMAL << " made by Default Constructor"
		<< std::endl;
}

Cat::Cat(const Cat& src)
	: Animal(src) {
	std::cout << GREEN << src.getType() << NORMAL << " made by Copy Constructor"
		<< std::endl;
	_type = src.getType();
}

Cat::~Cat(void) {
	std::cout << RED << _type << NORMAL << " Dead..." << std::endl;
}

Cat& Cat::operator=(const Cat& src) {
	std::cout << GREEN << src.getType() << NORMAL << " made by Assignment Operator"
		<< std::endl;
	if (this != &src) {
		_type = src.getType();
	}
	return *this;
}

void Cat::makeSound(void) const {
	std::cout << WC_SOUND << std::endl;
}
