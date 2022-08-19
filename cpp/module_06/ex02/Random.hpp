#ifndef RANDOM_HPP
#define RANDOM_HPP

#include <cstdlib>
#include <ctime>

class Random {
public:
	Random(void);
	Random(const Random& src);
	~Random(void);

	Random& operator=(const Random& src);

	int randNum(const double& min, const double& max) const;
};

#endif