#include "Data.hpp"

std::ostream& operator<<(std::ostream& os, const Data& obj) {
	return os << "Data : " << obj.getData() << std::endl
		<< "Str_Data : " << obj.getStr() << std::endl;
}

uintptr_t serialize(Data* ptr) {
	return reinterpret_cast<uintptr_t>(ptr);
}

Data* deserialize(uintptr_t raw) {
	return reinterpret_cast<Data *>(raw);
}

Data::Data(void) : _data(0), _str_data() {
}

Data::Data(const int& input, const std::string& str_data)
	: _data(input), _str_data(str_data) {
}

Data::Data(const Data& src)
	: _data(src.getData()), _str_data(src.getStr()) {
}

Data::~Data(void) {
}

Data& Data::operator=(const Data& src) {
	if (this != &src) {
		_data = src.getData();
		_str_data = src.getStr();
	}
	return *this;
}

const int& Data::getData(void) const {
	return _data;
}

const std::string& Data::getStr(void) const {
	return _str_data;
}
