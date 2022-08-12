#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include <iostream>
#include <string>

#include "ClapTrap.hpp"

#define S_EP	50

class ScavTrap : virtual public ClapTrap {
public:
	ScavTrap(void);
	ScavTrap(const std::string& name);
	ScavTrap(const ScavTrap& s);
	~ScavTrap(void);

	ScavTrap& operator=(const ScavTrap& copy);

	void attack(const std::string& target);
	void guardGate(void) const;
};

#endif