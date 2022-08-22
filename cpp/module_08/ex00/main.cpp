#include <iostream>
#include <vector>
#include <list>

#include "easyfind.hpp"

int main(void) {
	int arr[5] = {1, 3, 5, 7, 9};
	std::vector<int> v (arr, arr+5);
	std::list<int> l (arr, arr+5);
	std::vector<int>::iterator v_it;
	std::list<int>::iterator l_it;


	v_it = ::easyfind(v, 8);
	l_it = ::easyfind(l, 5);

	return 0;
}