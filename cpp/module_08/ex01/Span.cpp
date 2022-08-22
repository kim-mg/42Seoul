#include "Span.hpp"

Span::Span(void) : _cont(), _max_store(0) {
}

Span::Span(const unsigned int& N) : _cont(), _max_store(N) {
}

Span::Span(const Span& src) : _cont(src._cont), _max_store(src._max_store) {
}

Span::~Span(void) {
}

Span& Span::operator=(const Span& src) {
	if (this != &src) {
		_cont(src._cont);
		_max_store = src._max_store;
	}
	return *this;
}

void Span::addNumber(const int& num) {
	if (_max_store <= _cont.size())
		throw FullStorageException();
	_cont.push_back(num);
}

int