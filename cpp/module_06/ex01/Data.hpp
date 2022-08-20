#ifndef DATA_HPP
#define DATA_HPP

#include <stdint.h>

#include <iostream>

class Data {
private:
	int _data;
	std::string _str_data;

public:
	Data(void);
	Data(const int& data, const std::string& str_data);
	Data(const Data& src);
	~Data(void);

	Data& operator=(const Data& src);

	const int& getData(void) const;
	const std::string& getStr(void) const;
};

uintptr_t serialize(Data* ptr);
Data* deserialize(uintptr_t raw);
std::ostream& operator<<(std::ostream& os, const Data& obj);

#endif