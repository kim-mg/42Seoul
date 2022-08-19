#include "Random.hpp"

Random::Random(void) {
	std::srand(static_cast<unsigned int>(std::time(NULL)));
}

Random::Random(const Random& src) {
	static_cast<void>(src);
	std::srand(static_cast<unsigned int>(std::time(NULL)));
}

Random::~Random(void) {
}

Random& Random::operator=(const Random& src) {
	static_cast<void>(src);
	std::srand(static_cast<unsigned int>(std::time(NULL)));
	return *this;
}

int Random::randNum(const double& min, const double& max) const {
	const static double fraction = 1.0 / RAND_MAX;
	return min + static_cast<int>((max - min + 1) * (std::rand() * fraction));
}