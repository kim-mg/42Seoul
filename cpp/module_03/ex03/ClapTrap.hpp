#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <string>

#define RED			"\e[31m"
#define GREEN		"\e[32m"
#define YELLOW		"\e[33m"
#define BLUE		"\e[34m"
#define MAGENTA		"\e[35m"
#define NORMAL		"\e[0m"

class ClapTrap {
public:
	ClapTrap(void);
	ClapTrap(const std::string& name);
	ClapTrap(const ClapTrap& copy);
	~ClapTrap(void);

	ClapTrap& operator=(const ClapTrap& copy);

	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);

	void setName(const std::string& name);
	void setHit(const unsigned int points);
	void setEnergy(const unsigned int points);
	void setDamage(const unsigned int points);

	std::string getName(void) const;
	unsigned int getHit(void) const;
	unsigned int getEnergy(void) const;
	unsigned int getDamage(void) const;

protected:
	std::string _name;
	unsigned int _hit;
	unsigned int _energy;
	unsigned int _damage;

	void printState(void) const;
	bool checkState(void) const;
};

#endif