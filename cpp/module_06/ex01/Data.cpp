#include "Data.hpp"

std::ostream& operator<<(std::ostream& os, const Data& obj) {
	return os << "Data : " << obj.getData() << std::endl;
}

uintptr_t serialize(Data* ptr) {
	return reinterpret_cast<uintptr_t>(ptr);
}

Data* deserialize(uintptr_t raw) {
	return reinterpret_cast<Data *>(raw);
}

Data::Data(void) : _data(0) {
}

Data::Data(const int& input) : _data(input) {
}

Data::Data(const Data& src) : _data(src.getData()) {
}

Data::~Data(void) {
}

Data& Data::operator=(const Data& src) {
	if (this != &src)
		_data = src.getData();
	return *this;
}

const int& Data::getData(void) const {
	return _data;
}
