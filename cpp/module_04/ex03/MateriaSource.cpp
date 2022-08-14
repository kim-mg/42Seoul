#include "MateriaSource.hpp"
#include "IMateriaSource.hpp"
#include "AMateria.hpp"

MateriaSource::MateriaSource(void) {
	std::cout << GREEN << "MateriaSource Default" << NORMAL
		<< " Constructor" << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource& src) {
	for (int i = 0; i < M_SIZE; ++i) {
		if (_materia[i]) {
			delete _materia[i];
			_materia[i] = NULL;
		}
		_materia[i] = src.getAMateria(i);
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
		_name = src.getName();
		for (int i = 0; i < M_SIZE; ++i) {
			if (_materia[i]) {
				delete _materia[i];
				_materia[i] = NULL;
			}
			_materia[i] = src.getAMateria(i);
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
			std::cout << " Learn Materia type "
				<< BLUE << m->getType() << NORMAL << std::endl;
			return ;
		}
	}
	std::cout << "Learn Materia Fail : Materia memory is full" << std::endl;
}

AMateria* MateriaSource::createMateria(const std::string& type) {
	for (int i = 0; i < M_SIZE; ++i) {
		if (_materia[i] && _materia[i]->getType() == type) {
			std::cout << "Create Materia type " << BLUE << type
				<< NORMAL << std::endl;
			return _materia[i]->clone();
		}
	}
	std::cout << "Create Materia Fail : No have Materia type "
		<< BLUE << type << NORMAL << std::endl;
	return NULL;
}
