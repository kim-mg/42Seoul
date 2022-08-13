#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void)
	: ClapTrap("TempDiaimond_clap_name") {
	_name = "TempDiamond";
	_hit = F_HP;
	_energy = S_EP;
	_damage = F_DA;
	std::cout << "Default DiamondTrap " << MAGENTA << _name
		<< NORMAL << " is created" << std::endl;
}

DiamondTrap::DiamondTrap(const std::string& name)
	: ClapTrap(name + "_clap_name") {
	std::cout << "Naming DiamondTrap " << MAGENTA << name
		<< NORMAL << " is created" << std::endl;

	_name = name;
	_hit = F_HP;
	_energy = S_EP;
	_damage = F_DA;
}

DiamondTrap::DiamondTrap(const DiamondTrap& d)
	: ClapTrap(d), ScavTrap(d), FragTrap(d) {
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
		ClapTrap::_name = d._name + "_clap_trap";
		_name = d._name;
		_hit = d._hit;
		_energy = d._energy;
		_damage = d._damage;
	}
	return *this;
}

void DiamondTrap::whoAmI(void) const {
	std::cout << "I am " << MAGENTA << _name << NORMAL
		<<  " my ClapTrap name is " << MAGENTA
		<< ClapTrap::_name << NORMAL << std::endl;
}

void DiamondTrap::attack(const std::string& target) {
	ScavTrap::attack(target);
}

void DiamondTrap::setName(const std::string& name) {
	std::cout << MAGENTA << _name << NORMAL
		<< " change name to " << MAGENTA << name << NORMAL
		<< std::endl;
	_name = name;
}

void DiamondTrap::printState(void) const {
	std::cout << MAGENTA << _name << NORMAL << std::endl
		<< "HP : " << GREEN << _hit << NORMAL << std::endl
		<< "EP : " << YELLOW << _energy << NORMAL << std::endl
		<< "DA : " << BLUE << _damage << NORMAL << std::endl;
}
