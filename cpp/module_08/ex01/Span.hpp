#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>

class Span {
private:
	std::vector<int> _cont;
	int _max_store;

public:
	Span(void);
	Span(const unsigned int& N);
	Span(const Span& src);
	~Span(void);

	Span& operator=(const Span& src);

	void addNumber(const int& num);
	int shortestSpan(void) const;
	int longestSpan(void) const;
};

#endif