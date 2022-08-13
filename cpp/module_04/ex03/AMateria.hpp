#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <string>

#include "ICharacter.hpp"

class AMateria {
protected:

public:
	AMateria(void);
	AMateria(const std::string& type);
	AMateria(const AMateria& src);
	AMateria& operator=(const AMateria& src);
	virtual ~AMateria(void);

	const std::string& getType(void) const;

	virtual AMateria* clone(void) const = 0;
	virtual void use(ICharacter& target);
};

#endif