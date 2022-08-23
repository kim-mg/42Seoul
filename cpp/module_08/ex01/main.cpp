#include "Span.hpp"

#include <iostream>
#include <list>

int main(void) {
	Span sp = Span(5);

	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	std::cout << sp.shortestSpan() << std::endl; 
	std::cout << sp.longestSpan() << std::endl;

	int* arr = new int[10000];

	for (int i = 0; i < 10000; ++i) {
		if (i == 0)
			arr[i] = 500;
		else if (i == 9999)
			arr[i] = 10000;
		else if (i == 5000)
			arr[i] = 505;
		else
			arr[i] = 0;
	}

	std::list<int> l_arr(arr, arr + 10000);
	Span sp_ = Span(3);
	try {
		std::cout << sp_.shortestSpan() << std::endl;
		std::cout << sp_.longestSpan() << std::endl;
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	sp_.addNumber(1);
	sp_.addNumber(2);
	sp_.addNumber(3);

	std::list<int>::iterator l_b = l_arr.begin();
	std::list<int>::iterator l_e = l_arr.end();

	try {
		sp_.addIter(l_b, l_e);
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	try {
		sp_.addNumber(4);
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	try {
		sp_.setSize(10010);
		sp_.addIter(l_b, l_e);
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << sp_.shortestSpan() << std::endl;
	std::cout << sp_.longestSpan() << std::endl;

	delete[] arr;

	return 0;
}