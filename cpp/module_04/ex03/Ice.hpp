#ifndef ICE_HPP
#define ICE_HPP

#include <string>

#include "AMateria.hpp"

#define I_TYPE	"ice"

class Ice : public AMateria {
private:
	std::string _type;

public:
	Ice(void);
	Ice(const Ice& src);
	Ice& operator=(const Ice& src);
	virtual ~Ice(void);

	virtual Ice* clone(void) const;
	virtual void use(ICharacter& target);
};

#endif