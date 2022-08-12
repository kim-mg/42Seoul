#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void)
	: ClapTrap("TempScav") {
	std::cout << "Default ScavTrap " << MAGENTA << _name
		<< NORMAL << " is created" << std::endl;
	_hit = 100;
	_energy = 50;
	_damage = 20;
}

ScavTrap::ScavTrap(const std::string& name)
	: ClapTrap(name) {
	std::cout << "Naming ScavTrap " << MAGENTA << _name
		<< NORMAL << " is created" << std::endl;
	_hit = 100;
	_energy = 50;
	_damage = 20;
}

ScavTrap::ScavTrap(const ScavTrap& s)
	: ClapTrap(s._name) {
	std::cout << "Copy ScavTrap " << MAGENTA << s._name
		<< NORMAL << " is created" << std::endl;
	_name = s._name;
	_hit = s._hit;
	_energy = s._energy;
	_damage = s._damage;
}

ScavTrap::~ScavTrap(void) {
	std::cout << "ScavTrap " << MAGENTA << _name
		<< NORMAL << " is deleted" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& s) {
	std::cout << "Copy assignment operator ScavTrap " << MAGENTA << s._name
		<< NORMAL << " is created" << std::endl;
	if (this != &s) {
		_name = s._name;
		_hit = s._hit;
		_energy = s._energy;
		_damage = s._damage;
	}
	return *this;
}

void ScavTrap::attack(const std::string& target) {
	if (ClapTrap::checkState())
		return ;
	std::cout << "ScavTrap " << MAGENTA << _name
		<< NORMAL << " attacks " << RED << target << NORMAL
		<< ", causing " << BLUE << _damage << NORMAL
		<< " points of damage" << std::endl;
	--_energy;
}

void ScavTrap::guardGate(void) const {
	std::cout << MAGENTA << _name << NORMAL << " Gate keeper mode on" << std::endl;
}
