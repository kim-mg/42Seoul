#include "Animal.hpp"
#include "Brain.hpp"
#include "Dog.hpp"

Dog::Dog(void)
	: _dog_brain(new Brain()) {
	_type = D_TYPE;
	std::cout << GREEN << _type << NORMAL << " made by Default Constructor"
		<< std::endl;
}

Dog::Dog(const Dog& src)
	: Animal(src), _dog_brain(new Brain(*src.getBrain())) {
	std::cout << GREEN << src.getType() << NORMAL << " made by Copy Constructor"
		<< std::endl;
	_type = src.getType();
}

Dog::~Dog(void) {
	std::cout << RED << _type << NORMAL << " Dead..." << std::endl;
	delete _dog_brain;
}

Dog& Dog::operator=(const Dog& src) {
	std::cout << GREEN << src.getType() << NORMAL << " made by Assignment Operator"
		<< std::endl;
	if (this != &src) {
		_type = src.getType();
		_dog_brain = new Brain(*src.getBrain());
	}
	return *this;
}

const Brain* Dog::getBrain(void) const {
	return _dog_brain;
}

void Dog::makeSound(void) const {
	std::cout << D_SOUND << std::endl;
}
