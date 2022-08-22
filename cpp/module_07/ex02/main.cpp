#include <cstdlib>

#include <iostream>
#include <iomanip>
#include <Array.hpp>

#define MAX_VAL 10

int main(int, char**)
{
	Array<int> numbers(MAX_VAL);
	int* mirror = new int[MAX_VAL];
	srand(time(NULL));
	for (int i = 0; i < MAX_VAL; i++)
	{
		const int value = rand() % 100;
		numbers[i] = value;
		mirror[i] = value;
	}
	//SCOPE
	{
		Array<int> tmp = numbers;
		Array<int> test(tmp);
		std::cout << std::setw(15) << "nubers(n)" << "|"
			<< std::setw(15) << "tmp = numbers" << "|"
			<< std::setw(15) << "test(tmp)" << std::endl;
		for (int i = 0; i < MAX_VAL; i++)
		{
			std::cout << std::setw(15) << numbers[i] << "|"
				<< std::setw(15) << tmp[i] << "|"
				<< std::setw(15) << test[i] << std::endl;
		}
		std::cout << std::endl
			<< "=============== random mix ===============" << std::endl;
		std::cout << std::setw(15) << "nubers(n)" << "|"
			<< std::setw(15) << "tmp = numbers" << "|"
			<< std::setw(15) << "test(tmp)" << std::endl;
		for (unsigned int i = 0; i < numbers.size(); ++i) {
			tmp[i] = rand() % 100;
			test[i] = rand() % 100;
			std::cout << std::setw(15) << numbers[i] << "|"
				<< std::setw(15) << tmp[i] << "|"
				<< std::setw(15) << test[i] << std::endl;
		}
	}

	std::cout << std::endl
		<< "=============== check origin and mine ==============="
		<< std::endl;
	std::cout << std::setw(15) << "mirror" << "|"
		<< std::setw(15) << "numbers" << std::endl;
	for (int i = 0; i < MAX_VAL; i++)
	{
		std::cout << std::setw(15) << mirror[i] << "|"
			<< std::setw(15) << numbers[i] << std::endl;
		if (mirror[i] != numbers[i])
		{
			std::cerr << "didn't save the same value!!" << std::endl;
			return 1;
		}
	}
	std::cout << std::endl
		<< "=============== check index Out of bounds ==============="
		<< std::endl;
	try
	{
		numbers[-2] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		numbers[MAX_VAL] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	delete [] mirror;

	return 0;
}