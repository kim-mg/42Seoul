#include "ClapTrap.hpp"
#include "FragTrap.hpp"

FragTrap::FragTrap(void)
	: ClapTrap("TempFrag") {
	std::cout << "Default FragTrap " << MAGENTA << _name
		<< NORMAL << " is created" << std::endl;
	_hit = 100;
	_energy = 100;
	_damage = 30;
}

FragTrap::FragTrap(const std::string& name)
	: ClapTrap(name) {
	std::cout << "Naming FragTrap " << MAGENTA << _name
		<< NORMAL << " is created" << std::endl;
	_hit = 100;
	_energy = 100;
	_damage = 30;
}

FragTrap::FragTrap(const FragTrap& f)
	: ClapTrap(f._name) {
	std::cout << "Copy FragTrap " << MAGENTA << f._name
		<< NORMAL << " is created" << std::endl;
	_name = f._name;
	_hit = f._hit;
	_energy = f._energy;
	_damage = f._damage;
}

FragTrap::~FragTrap(void) {
	std::cout << "FragTrap " << MAGENTA << _name
		<< NORMAL << " is deleted" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& f) {
	std::cout << "Copy assignment operator FragTrap " << MAGENTA << f._name
		<< NORMAL << " is created" << std::endl;
	if (this != &f) {
		_name = f._name;
		_hit = f._hit;
		_energy = f._energy;
		_damage = f._damage;
	}
	return *this;
}

void FragTrap::highFivesGuys(void) const {
	std::cout << MAGENTA << _name << NORMAL << " request high fives" << std::endl;
}
