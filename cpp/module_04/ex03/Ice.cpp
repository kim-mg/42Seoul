#include "Ice.hpp"
#include "AMateria.hpp"
#include "ICharacter.hpp"

Ice::Ice(void)
	: AMateria(I_TYPE) {
	std::cout << GREEN << "Ice Default" << NORMAL
		<< " Constructor" << std::endl;
}

Ice::Ice(const std::string& type)
	: AMateria(type) {
	std::cout << GREEN << "Ice Naming" << NORMAL
		<< " Constructor" << std::endl;
}

Ice::Ice(const Ice& src)
	: AMateria(src) {
	std::cout << GREEN << "Ice Naming" << NORMAL
		<< " Constructor" << std::endl;
}

Ice::~Ice(void) {
	std::cout << GREEN << "Ice" << NORMAL
		<< " Destructor" << std::endl;
}

Ice& Ice::operator=(const Ice& src) {
	std::cout << GREEN << "Ice Assignment Operator" << NORMAL
		<< " Constructor" << std::endl;
	if (this != &src)
		_type = src.getType();
	return *this;
}

Ice* Ice::clone(void) const {
	return new Ice();
}

void Ice::use(ICharacter& target) {
	std::cout << BLUE << "* shoots an ice bolt at "
		<< RED << target.getName() << BLUE
		<< " *" << NORMAL << std::endl;
}
