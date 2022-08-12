#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include <iostream>
#include <string>

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap {
public:
	DiamondTrap(void);
	DiamondTrap(const std::string& name);
	DiamondTrap(const DiamondTrap& d);
	~DiamondTrap(void);

	DiamondTrap& operator=(const DiamondTrap& d);
	
	void whoAmI(void) const;
	void attack(const std::string& target);

	void setName(const std::string& name);

	void printState(void) const;

private:
	std::string _name;
};

#endif