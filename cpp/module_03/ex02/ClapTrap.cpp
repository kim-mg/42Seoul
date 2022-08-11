#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void)
	: _name("TempClap"), _hit(10), _energy(10), _damage(0) {
	std::cout << "Default ClapTrap " << MAGENTA << _name
		<< NORMAL << " is created" << std::endl;
}

ClapTrap::ClapTrap(const std::string& name)
	: _name(name), _hit(10), _energy(10), _damage(0) {
	std::cout << "Naming ClapTrap " << MAGENTA << _name
		<< NORMAL << " is created" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& copy)
	: _name(copy.getName()), _hit(copy.getHit())
		, _energy(copy.getEnergy()), _damage(copy.getDamage()) {
	std::cout << "Copy ClapTrap " << MAGENTA << _name
		<< NORMAL << " is created" << std::endl;
}

ClapTrap::~ClapTrap(void) {
	std::cout << "ClapTrap " << MAGENTA << _name
		<< NORMAL << " is deleted" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& copy) {
	std::cout << "Copy assignment operator ClapTrap " << MAGENTA << copy.getName()
		<< NORMAL << " is created" << std::endl;
	if (this != &copy) {
		_name = copy.getName();
		_hit = copy.getHit();
		_energy = copy.getEnergy();
		_damage = copy.getDamage();
	}
	return *this;
}

void ClapTrap::setName(const std::string& name) {
	std::cout << MAGENTA << _name << NORMAL
		<< " change name to " << MAGENTA << name << NORMAL
		<< std::endl;
	_name = name;
}

void ClapTrap::setHit(const unsigned int points) {
	_hit = points;
}

void ClapTrap::setEnergy(const unsigned int points) {
	_energy = points;
}

void ClapTrap::setDamage(const unsigned int points) {
	_damage = points;
}

std::string ClapTrap::getName(void) const {
	return _name;
}

unsigned int ClapTrap::getHit(void) const {
	return _hit;
}

unsigned int ClapTrap::getEnergy(void) const {
	return _energy;
}

unsigned int ClapTrap::getDamage(void) const {
	return _damage;
}

void ClapTrap::attack(const std::string& target) {
	if (checkState())
		return ;
	std::cout << MAGENTA << _name
		<< NORMAL << " attacks " << RED << target << NORMAL
		<< ", causing " << BLUE << _damage << NORMAL
		<< " points of damage" << std::endl;
	--_energy;
	printState();
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (checkState())
		return ;
	std::cout << MAGENTA << _name
		<< NORMAL << " has takes " << BLUE << amount << NORMAL
		<< " points of damage" << std::endl;
	if (amount > _hit)
		_hit = 0;
	else
		_hit -= amount;
	printState();
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (checkState())
		return ;
	std::cout << MAGENTA << _name
		<< NORMAL << " be repaired " << BLUE << amount << NORMAL
		<< " points of hits" << std::endl;
	_hit += amount;
	--_energy;
	printState();
}

void ClapTrap::printState(void) const {
	std::cout << MAGENTA << _name
		<< NORMAL << " >> hit : " << GREEN << _hit << NORMAL
		<< ", energy : " << YELLOW << _energy << NORMAL << std::endl;
}

bool ClapTrap::checkState(void) const {
	if (!_hit) {
		std::cout << MAGENTA << _name << NORMAL
			<< " does not work : " << GREEN << "HP 0" << NORMAL << std::endl;
		return true;
	}
	if (!_energy) {
		std::cout << MAGENTA << _name << NORMAL
			<< " does not work : " << YELLOW << "EP 0" << NORMAL << std::endl;
		return true;
	}
	return false;
}
