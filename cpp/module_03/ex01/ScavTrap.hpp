#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
public:
	ScavTrap(void);
	ScavTrap(const std::string& name);
	ScavTrap(const ScavTrap& s);
	~ScavTrap(void);

	ScavTrap& operator=(const ScavTrap& copy);

	void guardGate(void) const;
}

#endif