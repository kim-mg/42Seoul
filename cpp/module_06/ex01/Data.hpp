#ifndef DATA_HPP
#define DATA_HPP

#include <iostream>

class Data {
private:
	int _data;

public:
	Data(void);
	Data(const int& input);
	Data(const Data& src);
	~Data(void);

	Data& operator=(const Data& src);

	const int& getData(void) const;
};

uintptr_t serialize(Data* ptr);
Data* deserialize(uintptr_t raw);
std::ostream& operator<<(std::ostream& os, const Data& obj);

#endif