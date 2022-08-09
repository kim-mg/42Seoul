#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void)
	: _name(), _hit(10), _energy(10), _damage(0) {
	std::cout << "Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(const std::string& name)
	: _name(name), _hit(10), _energy(10), _damage(0) {
	std::cout << "ClapTrap " << _name << " is created" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& copy) {
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

ClapTrap::~ClapTrap(void) {
	std::cout << "ClapTrap " << _name << " is deleted" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& copy) {
	std::cout << "Copy Assignment operator called" << std::endl;
	if (this != &copy) {
		_name = copy.getName();
		_hit = copy.getHit();
		_energy = copy.getEnergy();
		_damage = copy.getDamage();
	}
	return *this;
}

void ClapTrap::setName(const std::string& name) {
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
	std::cout << "ClapTrap " << _name << " attacks " << target
		<< ", causing " << _damage << " points of damage" << std::endl;
	--_energy;
	printState();
}

void ClapTrap::takeDamage(unsigned int amount) {
	std::cout << "ClapTrap " << _name << " has takes " << amount
		<< " points of damage" << std::endl;
	if (amount > _hit)
		_hit = 0;
	else
		_hit -= amount;
	printState();
}

void ClapTrap::beRepaired(unsigned int amount) {
	std::cout << "ClapTrap " << _name << " be repaired " << amount
		<< " points of hits" << std::endl;
	if (amount + _hit > 100)
		_hit = 100;
	else
		_hit += amount;
	--_energy;
	printState();
}

void ClapTrap::printState(void) const {
	std::cout << "ClapTrap " << _name << " >> hit : " << _hit << ", energy : "
		<< _energy << std::endl;
}