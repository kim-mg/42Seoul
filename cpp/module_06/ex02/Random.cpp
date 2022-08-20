#include "Random.hpp"

Random::Random(void) {
}

Random::Random(const Random& src) {
	static_cast<void>(src);
}

Random::~Random(void) {
}

Random& Random::operator=(const Random& src) {
	static_cast<void>(src);
	return *this;
}

int Random::randNum(const double& min, const double& max) {
	static int seed = 0;
	const static double fraction = 1.0 / RAND_MAX;

	if (seed == 0) {
		seed = 1;
		std::srand(static_cast<unsigned int>(std::time(NULL)));
	}
	return min + static_cast<int>((max - min + 1) * (std::rand() * fraction));
}