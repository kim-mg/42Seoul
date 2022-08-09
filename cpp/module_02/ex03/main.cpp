#include <iostream>
#include "Point.hpp"

int main(void) {
	Point a(0, 0);
	Point b(5.0f, 10.f);
	Point c(10.0, 0.0);
	Point p1(5.0, 3.0);
	Point p2(10.0, 1.0);

	std::cout << "Point a : " << a.getX() << ", " << a.getY() << std::endl; 
	std::cout << "Point b : " << b.getX() << ", " << b.getY() << std::endl;
	std::cout << "Point c : " << c.getX() << ", " << c.getY() << std::endl;
	std::cout << "bsp Point p1 : " << p1.getX() << ", " << p1.getY() << std::endl;
	std::cout << "bsp Point p2 : " << p2.getX() << ", " << p2.getY() << std::endl;
	std::cout << std::endl;
	std::cout << "p1 bsp result : " << (bsp(a, b, c, p1) ? "inside" : "outside")
		<< std::endl;
	std::cout << "p2 bsp result : " << (bsp(a, b, c, p2) ? "inside" : "outside")
		<< std::endl;
	return 0;
}
