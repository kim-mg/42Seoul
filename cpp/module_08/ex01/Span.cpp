#include "Span.hpp"

const char* Span::FullStorageException::what(void) const throw() {
	return "Full numbers stored";
}

const char* Span::NoNumberStoredException::what(void) const throw() {
	return "No numbers stored";
}

const char* Span::NotEnoughSpaceException::what(void) const throw() {
	return "Not enough space in storage";
}

Span::Span(void) : _cont() {
}

Span::Span(const unsigned int& N) : _cont() {
	if (N)
		_cont.reserve(N);
}

Span::Span(const Span& src) : _cont(src._cont) {
}

Span::~Span(void) {
}

Span& Span::operator=(const Span& src) {
	if (this != &src)
		_cont = src.getCont();
	return *this;
}

void Span::setSize(const unsigned int& size) {
	if (size > _cont.capacity())
		_cont.reserve(size);
}

const std::vector<int>& Span::getCont(void) const {
	return _cont;
}

void Span::addNumber(const int& num) {
	if (_cont.size() >= _cont.capacity())
		throw FullStorageException();
	_cont.push_back(num);
}

int Span::shortestSpan(void) const {
	if (_cont.size() < 2)
		throw NoNumberStoredException();
	std::vector<int> copy(_cont);
	std::sort(copy.begin(), copy.end());
	int min_span = *(--copy.end());
	std::vector<int>::iterator ex = copy.begin();
	for (std::vector<int>::iterator cur = ++(copy.begin());
		cur != copy.end(); ++cur) {
		if (*cur - *ex < min_span)
			min_span = *cur - *ex;
		++ex;
	}
	return min_span;
}

int Span::longestSpan(void) const {
	if (_cont.size() < 2)
		throw NoNumberStoredException();
	std::vector<int> copy(_cont);
	std::sort(copy.begin(), copy.end());
	return *(--copy.end()) - *(copy.begin());
}
