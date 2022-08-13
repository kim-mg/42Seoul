#include "Brain.hpp"

Brain::Brain(void) {
	std::cout << BLUE << "Brain" << NORMAL << " Default Constructor"
		<< std::endl;
	for (int i = 0 ; i < 100; ++i)
		_ideas[i] = newIdea();
}

Brain::Brain(const Brain& src) {
	std::cout << BLUE << "Brain" << NORMAL << " Copy Constructor"
		<< std::endl;
	for (int i = 0; i < 100; ++i)
		_ideas[i] = src.getIdea(i);
}

Brain::~Brain(void) {
	std::cout << BLUE << "Brain" << NORMAL << " off..." << std::endl;
}

Brain& Brain::operator=(const Brain& src) {
	std::cout << BLUE << "Brain" << NORMAL << " Copy Assignment Operator"
		<< std::endl;
	if (this != &src) {
		for (int i = 0; i < 100; ++i)
			_ideas[i] = src.getIdea(i);
	}
	return *this;
}

void Brain::setIdea(const int& i, const std::string& idea) {
	_ideas[i] = idea;
}

std::string Brain::getIdea(const int& i) const {
	return _ideas[i];
}

std::string Brain::newIdea(void) const {
	std::string objs[5] = {"PLAY", "FOOD", "SNACK", "SLEEP", "PARK"};
	static time_t tm = 0;

	if (!tm) {
		tm = std::time(0);
		std::srand(static_cast<unsigned int>(std::time(0)));
	}
	return objs[std::rand() % 5];
}

void Brain::showBrain(void) const {
	std::string colors[4] = {RED, GREEN, YELLOW, BLUE};
	for (int i = 0; i < 100; ++i) {
		std::cout << colors[i % 4] << _ideas[i] << NORMAL;
		if (i % 10 == 9)
			std::cout << std::endl;
		else
			std::cout << " ";
	}
}
