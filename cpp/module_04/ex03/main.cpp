#include <iostream>

#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"

int main() {
	std::cout << YELLOW << "================ Test 1 ================"
		<< NORMAL << std::endl;
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	std::cout << std::endl;

	ICharacter* me = new Character("me");
	std::cout << std::endl;
	
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	std::cout << std::endl;

	ICharacter* bob = new Character("bob");

	me->use(0, *bob);
	me->use(1, *bob);
	std::cout << std::endl;

	delete bob;
	delete me;
	delete src;
	std::cout << std::endl << std::endl;

	std::cout << YELLOW << "================ Test 2 ================"
		<< NORMAL << std::endl;

	IMateriaSource* msrc = new MateriaSource();
	msrc->learnMateria(new Ice());
	msrc->learnMateria(new Cure());
	msrc->learnMateria(new Cure());
	msrc->learnMateria(new Ice());
	msrc->learnMateria(new Ice());
	std::cout << std::endl;

	ICharacter* tom = new Character("tom");
	tmp = msrc->createMateria("cure");
	tom->equip(tmp);
	tmp = msrc->createMateria("fire");
	tom->equip(tmp);
	std::cout << std::endl;

	ICharacter* lim = new Character("lim");

	tom->use(0, *lim);
	tom->use(1, *lim);

	tom->unequip(1);
	tom->unequip(0);

	tom->use(0, *lim);
	std::cout << std::endl;

	delete lim;
	delete tom;
	delete msrc;
	std::cout << std::endl;

	return 0;
}