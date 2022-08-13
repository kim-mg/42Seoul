#include "Animal.hpp"
#include "Brain.hpp"
#include "Cat.hpp"

Cat::Cat(void) 
	: _cat_brain(new Brain()) {
	_type = C_TYPE;
	std::cout << GREEN << _type << NORMAL << " made by Default Constructor"
		<< std::endl;
}

Cat::Cat(const Cat& src)
	: Animal(src), _cat_brain(new Brain(*src.getBrain())) {
	std::cout << GREEN << src.getType() << NORMAL << " made by Copy Constructor"
		<< std::endl;
	_type = src.getType();
}

Cat::~Cat(void) {
	std::cout << RED << _type << NORMAL << " Dead..." << std::endl;
	delete _cat_brain;
}

Cat& Cat::operator=(const Cat& src) {
	std::cout << GREEN << src.getType() << NORMAL << " made by Assignment Operator"
		<< std::endl;
	if (this != &src) {
		_type = src.getType();
		_cat_brain = new Brain(*src.getBrain());
	}
	return *this;
}

const Brain* Cat::getBrain(void) const {
	return _cat_brain;
}

void Cat::makeSound(void) const {
	std::cout << C_SOUND << std::endl;
}
