#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <iostream>
#include <string>

#include "ICharacter.hpp"

#define RED			"\e[31m"
#define GREEN		"\e[32m"
#define YELLOW		"\e[33m"
#define BLUE		"\e[34m"
#define MAGENTA		"\e[35m"
#define NORMAL		"\e[0m"

class AMateria {
protected:
	std::string _type;

public:
	AMateria(void);
	AMateria(const std::string& type);
	AMateria(const AMateria& src);
	virtual ~AMateria(void);

	const std::string& getType(void) const;

	virtual AMateria* clone(void) const = 0;
	virtual void use(ICharacter& target);
};

#endif