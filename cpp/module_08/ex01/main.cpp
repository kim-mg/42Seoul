#include <iostream>
#include <vector>

#include "Span.hpp"

int main(void) {
	Span sp = Span(5);

	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	for (std::vector<int>::iterator it = sp.getCont().begin(); it != sp.getCont().end(); ++it) {
		std::cout << *it << std::endl;
	}

	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	return 0;
}