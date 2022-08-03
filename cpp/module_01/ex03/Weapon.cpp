#include "Weapon.hpp"

void Weapon::setType(const std::string& type) {
	_type = type;
}

std::string Weapon::getType(void) const {
	return _type;
}

Weapon::Weapon(void) {
}

Weapon::Weapon(const std::string& type)
	: _type(type) {
}

Weapon::~Weapon(void) {
}
