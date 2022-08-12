#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include <iostream>
#include <string>

#include "ClapTrap.hpp"

#define F_HP	100
#define F_DA	30

class FragTrap : virtual public ClapTrap {
public:
	FragTrap(void);
	FragTrap(const std::string& name);
	FragTrap(const FragTrap& s);
	~FragTrap(void);

	FragTrap& operator=(const FragTrap& copy);

	void highFivesGuys(void) const;
};

#endif