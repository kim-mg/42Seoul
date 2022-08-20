#include <iostream>

#include "iter.hpp"

int main(void) {
	int i_arr[5] = {0, 2, 4, 6, 8};
	std::string s_arr[5] = {"A", "B", "C", "D", "E"};
	double d_arr[5] = {0.1, 0.3, 0.5, 0.9, 1.1};
	bool b_arr[5] = {true, false, false, true, true};

	::iter(i_arr, sizeof(i_arr) / sizeof(int), ::print);
	std::cout << std::endl;
	::iter(s_arr, sizeof(s_arr) / sizeof(*s_arr), ::print);
	std::cout << std::endl;
	::iter(d_arr, sizeof(d_arr) / sizeof(*d_arr), ::print);
	std::cout << std::endl;
	::iter(b_arr, sizeof(b_arr) / sizeof(bool), ::print);
	std::cout << std::endl;
	return 0;
}