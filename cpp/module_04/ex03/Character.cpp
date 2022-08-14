// #include "AMateria.hpp"
#include "Character.cpp"

Character::Character(void)
	: _name() {
	std::cout << MAGENTA << "Character Default" << NORMAL
		<< " Constructor" << std::endl;
}

Character::Character(const std::string& name)
	: _name(name) {
	std::cout << MAGENTA << "Character Naming" << NORMAL
		<< " Constructor" << std::endl;
}

Character::Character(const Character& src)
	: _name(src.getName()) {
	for (int i = 0; i < AM_SIZE; ++i) {
		if (_materia[i]) {
			delete _materia[i];
			_materia[i] = NULL;
		}
		_materia[i] = src.getAMateria(i);
	}
	std::cout << MAGENTA << "Character Copy" << NORMAL
		<< " Constructor" << std::endl;
}

Character::~Character(void) {
	for (int i = 0; i < AM_SIZE; ++i) {
		if (_materia[i]) {
			delete _materia[i];
			_materia[i] = NULL;
		}
	}
	std::cout << MAGENTA << "Character" << NORMAL
		<< " Destructor" << std::endl;
}

Character& Character::operator=(const Character& src) {
	std::cout << MAGENTA << "Character Assignment Operator" << NORMAL
		<< " Constructor" << std::endl;
	if (this != &src) {
		_name = src.getName();
		for (int i = 0; i < AM_SIZE; ++i) {
			if (_materia[i]) {
				delete _materia[i];
				_materia[i] = NULL;
			}
			_materia[i] = src.getAMateria(i);
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
	for (int i = 0; i < AM_SIZE; ++i) {
		if (!_materia[i]) {
			_materia[i] = m;
			std::cout << MAGENTA << _name << NORMAL
				<< " Equip Materia Inventory "
				<< GREEN << i << NORMAL << std::endl;
			return ;
		}
	}
	std::cout << MAGENTA << _name << NORMAL
		<< " Equip Fail : Inventory is full" << std::endl;
}

void Character::unequip(int idx) {
	if (0 <= idx && idx < AM_SIZE && _materia[idx]) {
		_materia[idx] = NULL;
		std::cout << MAGENTA << _name << NORMAL
			<< " Unequip Materia Inventory "
			<< GREEN << NORMAL << std::endl;
		return ;
	}
	std::cout << MAGENTA << _name << NORMAL
		<< " Unequip Fail : No Materia in Inventory "
		<< YELLOW << idx << NORMAL << std::endl;
}

void Character::use(int idx, ICharacter& target) {
	if (0 <= idx && idx < AM_SIZE && _materia[idx]) {
		_materia[idx]->use(target);
		return ;
	}
	std::cout << MAGENTA << _name << NORMAL
		<< " Use Fail : No Materia in Inventory "
		<< YELLOW << idx << NORMAL << std::endl;
}
