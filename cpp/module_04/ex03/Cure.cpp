#include "Cure.hpp"
#include "AMateria.hpp"
#include "ICharacter.hpp"

Cure::Cure(void)
	: AMateria(C_TYPE) {
	std::cout << GREEN << "Cure Default" << NORMAL
		<< " Constructor" << std::endl;
}

Cure::Cure(const std::string& type)
	: AMateria(type) {
	std::cout << GREEN << "Cure Naming" << NORMAL
		<< " Constructor" << std::endl;
}

Cure::Cure(const Cure& src)
	: AMateria(src) {
	std::cout << GREEN << "Cure Naming" << NORMAL
		<< " Constructor" << std::endl;
}

Cure::~Cure(void) {
	std::cout << GREEN << "Cure" << NORMAL
		<< " Destructor" << std::endl;
}

// Cure& Cure::operator=(const Cure& src) {
// 	std::cout << GREEN << "Cure Assignment Operator" << NORMAL
// 		<< " Constructor" << std::endl;
// 	if (this != &src)
// 		_type = src.getType();
// 	return *this;
// }

Cure* Cure::clone(void) const {
	return new Cure();
}

void Cure::use(ICharacter& target) {
	std::cout << GREEN << "* heals "
		<< YELLOW << target.getName() << GREEN
		<< "'s wounds *" << NORMAL << std::endl;
}
