#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

WrongCat::WrongCat(void) {
	_type = C_TYPE;
	std::cout << GREEN << _type << NORMAL << " made by Default Constructor"
		<< std::endl;
}

WrongCat::WrongCat(const WrongCat& src)
	: WrongAnimal(src) {
	std::cout << GREEN << src.getType() << NORMAL << " made by Copy Constructor"
		<< std::endl;
	_type = src.getType();
}

WrongCat::~WrongCat(void) {
	std::cout << RED << _type << NORMAL << " Dead..." << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& src) {
	std::cout << GREEN << src.getType() << NORMAL << " made by Assignment Operator"
		<< std::endl;
	if (this != &src) {
		_type = src.getType();
	}
	return *this;
}

void WrongCat::makeSound(void) const {
	std::cout << C_SOUND << std::endl;
}
