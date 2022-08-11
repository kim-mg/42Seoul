#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void)
	: ClapTrap("TempClap_clap_name") {
	_name = "TempDiamond";
	_hit = FragTrap::_hit;
	_energy = ScavTrap::_energy;
	_damage = FragTrap::_damage;
	std::cout << "Default DiamondTrap " << MAGENTA << _name
		<< NORMAL << " is created" << std::endl;
}

DiamondTrap::DiamondTrap(const std::string& name)
	: ClapTrap(name + "_clap_name"), {
	std::cout << "Naming DiamondTrap " << MAGENTA << name
		<< NORMAL << " is created" << std::endl;
	_name = name;
	_hit = FragTrap::_hit;
	_energy = ScavTrap::_energy;
	_damage = FragTrap::_damage;
}

DiamondTrap::DiamondTrap(const DiamondTrap& d) {
	std::cout << "Copy DiamondTrap " << MAGENTA << d._name
		<< NORMAL << " is created" << std::endl;
	_name = d._name;
	_hit = d._hit;
	_energy = d._energy;
	_damage = d._damage;
}

DiamondTrap::~DiamondTrap(void) {
	std::cout << "DiamondTrap " << MAGENTA << _name
		<< NORMAL << " is deleted" << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& d) {
	std::cout << "Copy assignment operator DiamondTrap " << MAGENTA << d._name
		<< NORMAL << " is created" << std::endl;
	if (this != &d) {
		_name = d._name;
		_hit = d._hit;
		_energy = d._energy;
		_damage = d._damage;
	}
	return *this;
}

void DiamondTrap::whoAmI(void) const {
	std::cout << "i am " << MAGENTA << _name << NORMAL
		<<  " my ClapTrap name is " << MAGENTA
		<< ClapTrap::_name << NORMAL << std::endl;
}

void DiamondTrap::attack(const std::string& target) {
	ScavTrap::attack(target);
}
