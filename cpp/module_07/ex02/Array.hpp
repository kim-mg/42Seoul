#ifndef ARRAY_HPP
#define ARRAY_HPP

template <typename T>
class Array {
private:

public:
	Array(void);
	Array(const unsigned int& size);
	Array(const Array& src);
	~Array(void);

	Array& operator=(const Array& src);
	Array& operator[](const Array& src);

	const std::size_t& size(void) const;
};

#endif