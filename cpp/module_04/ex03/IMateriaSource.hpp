#ifndef IMATERIASOURCE_HPP
#define IMATERIASOURCE_HPP

#include <string>

#include "AMateria.hpp"

#define RED			"\e[31m"
#define GREEN		"\e[32m"
#define YELLOW		"\e[33m"
#define BLUE		"\e[34m"
#define MAGENTA		"\e[35m"
#define NORMAL		"\e[0m"

class IMateriaSource {
public:
	virtual ~IMateriaSource(void) {}
	virtual void learnMateria(AMateria* m) = 0;
	virtual AMateria* createMateria(const std::string& type) = 0;
};

#endif