#ifndef CURE_HPP
#define CURE_HPP

#include <string>

#include "AMateria.hpp"

#define C_TYPE	"cure"

class Cure : public AMateria {
private:
	std::string _type;

public:
	Cure(void);
	Cure(const Cure& src);
	Cure& operator=(const Cure& src);
	virtual ~Cure(void);

	virtual Cure* clone(void) const;
	virtual void use(ICharacter& target);
};

#endif