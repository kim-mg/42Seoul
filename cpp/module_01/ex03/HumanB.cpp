#include "HumanB.hpp"
#include "Weapon.hpp"

void HumanB::attack(void) const {
	std::cout << _name << " attacks with their "
		<< _weapon->getType() << std::endl;
}

void HumanB::setWeapon(Weapon &weapon) {
	_weapon = &weapon;
}

HumanB::HumanB(void) {
}

HumanB::HumanB(const std::string& name)
	: _name(name), _weapon(NULL) {
}

HumanB::~HumanB(void) {
}