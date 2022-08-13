#include "AMateria.hpp"
#include <iostream>

int main() {
	// IMateriaSource* src = new MateriaSource();
	// src->learnMateria(new Ice());
	// src->learnMateria(new Cure());

	// ICharacter* me = new Character("me");

	// AMateria* tmp;
	AMateria tmp = AMateria();
	std::cout << tmp.getType() << std::endl;
	// tmp = src->createMateria("ice");
	// me->equip(tmp);
	// tmp = src->createMateria("cure");
	// me->equip(tmp);

	// ICharacter* bob = new Charactern("bob");

	// me->use(0, *bob);
	// me->use(1, *bob);

	// delete bob;
	// delete me;
	// delete src;

	return 0;
}