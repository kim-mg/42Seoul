#ifndef ICE_HPP
#define ICE_HPP

#include <string>

#include "AMateria.hpp"

#define I_TYPE	"ice"

class Ice : public AMateria {
public:
	Ice(void);
	Ice(const std::string& type);
	Ice(const Ice& src);
	Ice& operator=(const Ice& src);
	virtual ~Ice(void);

	virtual Ice* clone(void) const;
	virtual void use(ICharacter& target);
};

#endif