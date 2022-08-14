#ifndef ICHARACTER_HPP
#define ICHARACTER_HPP

#include <string>

#include "AMateria.hpp"

#define RED			"\e[31m"
#define GREEN		"\e[32m"
#define YELLOW		"\e[33m"
#define BLUE		"\e[34m"
#define MAGENTA		"\e[35m"
#define NORMAL		"\e[0m"

class ICharacter {
public:
	virtual ~ICharacter(void) {}
	virtual const std::string& getName(void) const = 0;
	virtual void equip(AMateria* m) = 0;
	virtual void unequip(int idx) = 0;
	virtual void use(int idx, ICharacter& target) = 0;
};

#endif