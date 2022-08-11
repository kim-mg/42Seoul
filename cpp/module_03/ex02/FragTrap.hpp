#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include <iostream>
#include <string>

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap {
public:
	FragTrap(void);
	FragTrap(const std::string& name);
	FragTrap(const FragTrap& s);
	~FragTrap(void);

	FragTrap& operator=(const FragTrap& copy);

	void highFivesGuys(void) const;
};

#endif