#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>

class Weapon {
private:
	std::string _type;

	Weapon(void);

public:
	void setType(const std::string& type);
	std::string getType(void) const;

	explicit Weapon(const std::string& type);
	~Weapon(void);
};

#endif