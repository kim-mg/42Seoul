#include "AMateria.hpp"
#include "Character.hpp"

Character::Character(void)
	: _name() {
	for (int i = 0; i < AM_SIZE; ++i)
		_materia[i] = NULL;
	std::cout << MAGENTA << "Character Default" << NORMAL
		<< " Constructor" << std::endl;
}

Character::Character(const std::string& name)
	: _name(name) {
	for (int i = 0; i < AM_SIZE; ++i)
		_materia[i] = NULL;
	std::cout << MAGENTA << _name << YELLOW << " Character Naming" << NORMAL
		<< " Constructor" << std::endl;
}

Character::Character(const Character& src)
	: _name(src.getName()) {
	for (int i = 0; i < AM_SIZE; ++i) {
		if (_materia[i]) {
			delete _materia[i];
			_materia[i] = NULL;
		}
		if (src.getAMateria(i))
			_materia[i] = src.getAMateria(i)->clone();
	}
	std::cout << MAGENTA << _name << YELLOW << " Character Copy" << NORMAL
		<< " Constructor" << std::endl;
}

Character::~Character(void) {
	for (int i = 0; i < AM_SIZE; ++i) {
		if (_materia[i]) {
			delete _materia[i];
			_materia[i] = NULL;
		}
	}
	std::cout << MAGENTA << _name << YELLOW << " Character" << NORMAL
		<< " Destructor" << std::endl;
}

Character& Character::operator=(const Character& src) {
	std::cout << MAGENTA << src.getName()
		<< YELLOW << "Character Assignment Operator" << NORMAL
		<< " Constructor" << std::endl;
	if (this != &src) {
		_name = src.getName();
		for (int i = 0; i < AM_SIZE; ++i) {
			if (_materia[i]) {
				delete _materia[i];
				_materia[i] = NULL;
			}
			_materia[i] = src.getAMateria(i)->clone();
		}
	}
	return *this;
}

const AMateria* Character::getAMateria(int idx) const {
	return _materia[idx];
}

const std::string& Character::getName(void) const {
	return _name;
}

void Character::equip(AMateria* m) {
	if (!m) {
		std::cout << MAGENTA << _name << NORMAL
			<< " Equip Fail : No Materia" << std::endl;
		return ;
	}
	for (int i = 0; i < AM_SIZE; ++i) {
		if (!_materia[i]) {
			_materia[i] = m;
			std::cout << MAGENTA << _name << NORMAL
				<< " Equip Materia TYPE : "
				<< BLUE << m->getType() << NORMAL
				<< " Inventory "
				<< GREEN << i << NORMAL << std::endl;
			return ;
		}
	}
	std::cout << MAGENTA << _name << NORMAL
		<< " Equip Fail : Inventory is full" << std::endl;
}

void Character::unequip(int idx) {
	std::string type;

	if (0 <= idx && idx < AM_SIZE && _materia[idx]) {
		type = _materia[idx]->getType();
		_materia[idx] = NULL;
		std::cout << MAGENTA << _name << NORMAL
			<< " Unequip Materia TYPE : "
			<< BLUE << type << NORMAL
			<< " Inventory "
			<< GREEN << idx << NORMAL << std::endl;
		return ;
	}
	std::cout << MAGENTA << _name << NORMAL
		<< " Unequip Fail : No Materia in Inventory "
		<< YELLOW << idx << NORMAL << std::endl;
}

void Character::use(int idx, ICharacter& target) {
	if (0 <= idx && idx < AM_SIZE && _materia[idx]) {
		std::cout << MAGENTA << _name << NORMAL << " ";
		_materia[idx]->use(target);
		return ;
	}
	std::cout << MAGENTA << _name << NORMAL
		<< " Use Fail : No Materia in Inventory "
		<< YELLOW << idx << NORMAL << std::endl;
}
