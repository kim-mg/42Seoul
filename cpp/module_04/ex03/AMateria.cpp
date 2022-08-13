#include "AMateria.hpp"
#include "ICharacter.hpp"

AMateria::AMateria(void)
	: _type() {
	std::cout << GREEN << "AMatreia Default" << NORMAL
		<< " Constructor" << std::endl;
}

AMateria::AMateria(const std::string& type)
	: _type(type) {
	std::cout << GREEN << "AMatreia Naming" << NORMAL
		<< " Constructor" << std::endl;
}

AMateria::~AMateria(void) {
	std::cout << GREEN << "AMatreia" << NORMAL
		<< " Destructor" << std::endl;
}

const std::string& AMateria::getType(void) const {
	return _type;
}

void AMateria::use(ICharacter& target) {
	std::cout << BLUE << "use AMateria" << NORMAL
		<< " to " << target.getName() << std::endl;
}
