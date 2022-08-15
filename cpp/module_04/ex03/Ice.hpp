#ifndef ICE_HPP
#define ICE_HPP

#include <iostream>
#include <string>

#include "AMateria.hpp"

#define I_TYPE	"ice"

class Ice : public AMateria {
public:
	Ice(void);
	Ice(const std::string& type);
	Ice(const Ice& src);
	virtual ~Ice(void);

	Ice& operator=(const Ice& src);

	Ice* clone(void) const;
	void use(ICharacter& target);
};

#endif