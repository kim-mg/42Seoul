#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include <iostream>
#include <string>

#include "IMateriaSource.hpp"

#define M_SIZE	4

class MateriaSource : public IMateriaSource {
private:
	AMateria* _materia[M_SIZE];

public:
	MateriaSource(void);
	MateriaSource(const MateriaSource& src);
	virtual ~MateriaSource(void);

	MateriaSource& operator=(const MateriaSource& src);

	const AMateria* getAMateria(int idx) const;
	void learnMateria(AMateria* m);
	AMateria* createMateria(const std::string& type);
};

#endif