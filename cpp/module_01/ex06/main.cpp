#include "Harl.hpp"

int main(int argc, char **argv) {
	Harl harl;

	if (--argc != 1) {
		std::cout << "Error: need only one filter level." << std::endl;
		return 1;
	}
	harl.complain(argv[1]);
	return 0;
}