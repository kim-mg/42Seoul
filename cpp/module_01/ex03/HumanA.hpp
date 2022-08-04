#ifndef HUMANA_HPP
#define HUMANA_HPP

#include <iostream>
#include <string>

#include "Weapon.hpp"

class HumanA {
private:
	std::string _name;
	Weapon &_weapon;

	HumanA(void);

public:
	void attack(void) const;

	explicit HumanA(const std::string& name, Weapon weapon);
	~HumanA(void);
};

#endif