#include <iostream>
#include <string>

int main(void) {
	const std::string string = "HI THIS IS BRAIN";
	const std::string *stringPTR = &string;
	const std::string &stringREF = string;

	std::cout << "string address : " << &string << std::endl
		<< "stringPTR address : " << stringPTR << std::endl
		<< "stringREF address : " << &stringREF << std::endl
		<< std::endl;
	std::cout << "string value : " << string << std::endl
		<< "stringPTR value : " << *stringPTR << std::endl
		<< "stringREF value : " << stringREF << std::endl;
	return 0;
}
