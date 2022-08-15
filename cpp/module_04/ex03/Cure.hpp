#ifndef CURE_HPP
#define CURE_HPP

#include <iostream>
#include <string>

#include "AMateria.hpp"

#define C_TYPE	"cure"

class Cure : public AMateria {
public:
	Cure(void);
	Cure(const std::string& type);
	Cure(const Cure& src);
	virtual ~Cure(void);

	Cure& operator=(const Cure& src);

	Cure* clone(void) const;
	void use(ICharacter& target);
};

#endif