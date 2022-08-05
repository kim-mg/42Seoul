#ifndef HUMANB_HPP
#define HUMANB_HPP

#include <iostream>
#include <string>

#include "Weapon.hpp"

class HumanB {
private:
	std::string _name;
	Weapon *_weapon;

	HumanB(void);

public:
	void attack(void) const;
	void setWeapon(Weapon& weapon);

	explicit HumanB(const std::string& name);
	~HumanB(void);
};

#endif