#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <exception>

template <typename T>
class Array {
private:
	T* _arr;
	unsigned int _size;

public:
	Array(void) : _arr(NULL), _size(0) {}
	Array(const unsigned int& size) : _arr(NULL), _size(size) {
		if (_size)
			_arr = new T[_size];
	}
	Array(const Array& src) : _arr(NULL), _size(src.size()) {
		if (_size)
			_arr = new T[_size];
		for (unsigned int i = 0; i < _size; ++i)
			_arr[i] = src[i];
	}
	~Array(void) {
		if (_size) {
			delete[] _arr;
			_arr = NULL;
		}
	}

	Array& operator=(const Array& src) {
		if (this != &src) {
			if (_size) {
				delete[] _arr;
				_arr = NULL;
			}
			_size = src.size();
			if (_size)
				_arr = new T[_size];
			for (unsigned int i = 0; i < _size; ++i)
				_arr[i] = src[i];
		}
		return *this;
	}
	T& operator[](const unsigned int& idx) {
		if (idx >= _size)
			throw OutOfBoundException();
		return _arr[idx];
	}
	const T& operator[](const unsigned int& idx) const {
		if (idx >= _size)
			throw OutOfBoundException();
		return _arr[idx];
	}

	const unsigned int& size(void) const {return _size;}

	class OutOfBoundException : public std::exception {
	public:
		const char* what(void) const throw() {
			return "Segmentation fault : Out of bounds";
		}
	};
};

#endif