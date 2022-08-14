#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <iostream>
#include <string>

#include "ICharacter.hpp"

#define AM_SIZE	4

class AMateria;

class Character : public ICharacter {
private:
	AMateria* _materia[AM_SIZE];
	std::string _name;

public:
	Character(void);
	explicit Character(const std::string& name);
	Character(const Character& src);
	virtual ~Character(void);

	Character& operator=(const Character& src);

	const AMateria* getAMateria(int idx) const;
	const std::string& getName(void) const;
	void equip(AMateria* m);
	void unequip(int idx);
	void use(int idx, ICharacter& target);
};

#endif