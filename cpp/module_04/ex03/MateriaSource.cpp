#include "MateriaSource.hpp"
#include "IMateriaSource.hpp"
#include "AMateria.hpp"

MateriaSource::MateriaSource(void) {
	for (int i = 0; i < M_SIZE; ++i)
		_materia[i] = NULL;
	std::cout << GREEN << "MateriaSource Default" << NORMAL
		<< " Constructor" << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource& src) {
	for (int i = 0; i < M_SIZE; ++i) {
		if (_materia[i]) {
			delete _materia[i];
			_materia[i] = NULL;
		}
		_materia[i] = src.getAMateria(i)->clone();
	}
	std::cout << GREEN << "MateriaSource Copy" << NORMAL
		<< " Constructor" << std::endl;
}

MateriaSource::~MateriaSource(void) {
	for (int i = 0; i < M_SIZE; ++i) {
		if (_materia[i]) {
			delete _materia[i];
			_materia[i] = NULL;
		}
	}
	std::cout << GREEN << "MateriaSource" << NORMAL
		<< " Destructor" << std::endl;
}

MateriaSource& MateriaSource::operator=(const MateriaSource& src) {
	std::cout << GREEN << "MateriaSource Assignment Operator" << NORMAL
		<< " Constructor" << std::endl;
	if (this != &src) {
		for (int i = 0; i < M_SIZE; ++i) {
			if (_materia[i]) {
				delete _materia[i];
				_materia[i] = NULL;
			}
			_materia[i] = src.getAMateria(i)->clone();
		}
	}
	return *this;
}

const AMateria* MateriaSource::getAMateria(int idx) const {
	return _materia[idx];
}

void MateriaSource::learnMateria(AMateria* m) {
	for (int i = 0; i < M_SIZE; ++i) {
		if (!_materia[i]) {
			_materia[i] = m;
			std::cout << "  >> MateriaSource Learn Materia type "
				<< BLUE << m->getType() << NORMAL << std::endl;
			return ;
		}
	}
	std::cout << "  >> MateriaSource Learn Materia Fail : Materia memory is full"
		<< std::endl;
}

AMateria* MateriaSource::createMateria(const std::string& type) {
	for (int i = 0; i < M_SIZE; ++i) {
		if (_materia[i] && _materia[i]->getType() == type) {
			std::cout << "  >> MateriaSource Create Materia type " << BLUE << type
				<< NORMAL << std::endl;
			return _materia[i]->clone();
		}
	}
	std::cout << "  >> MateriaSource Create Materia Fail : Unknown Materia type "
		<< BLUE << type << NORMAL << std::endl;
	return 0;
}
