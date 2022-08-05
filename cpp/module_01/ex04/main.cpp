#include "Replace.hpp"

int main(int argc, char **argv) {
	if (--argc != 3) {
		std::cout << "Error: do not satisfied format." << std::endl
			<< "usage : ./replace filename str1 str2" << std::endl;
		return 1;
	}
	Replace::replaceFile(argv[1], argv[2], argv[3]);
	return 0;
}
