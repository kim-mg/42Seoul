#ifndef SPAN_HPP
#define SPAN_HPP

#include <exception>
#include <algorithm>
#include <iterator>
#include <vector>

class Span {
private:
	std::vector<int> _cont;

public:
	Span(void);
	Span(const unsigned int& N);
	Span(const Span& src);
	~Span(void);

	Span& operator=(const Span& src);

	void setSize(const unsigned int& size);
	const std::vector<int>& getCont(void) const;
	
	void addNumber(const int& num);
	int shortestSpan(void) const;
	int longestSpan(void) const;

	template <typename T>
	void addIter(T& begin, T& end) {
		if (std::distance(begin, end) > static_cast<int>(_cont.capacity() - _cont.size()))
			throw NotEnoughSpaceException();
		while (begin != end)
			_cont.push_back(*begin++);
	}

	class FullStorageException : public std::exception {
	public:
		const char* what(void) const throw();
	};

	class NoNumberStoredException : public std::exception {
	public:
		const char* what(void) const throw();
	};

	class NotEnoughSpaceException : public std::exception {
	public:
		const char* what(void) const throw();
	};
};

#endif