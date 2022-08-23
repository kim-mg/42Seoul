#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>

template <typename T>
class MutantStack : public std::stack<T> {
public:
	typedef typename std::stack<T>::container_type::iterator iterator;
	typedef typename std::stack<T>::container_type::const_iterator const_iterator;
	typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
	typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;
	

	MutantStack(void) {}
	MutantStack(const MutantStack& src) { *this = src; }
	~MutantStack(void) {}

	MutantStack& operator=(const MutantStack& src) { 
		if (this != &src)
			std::stack<T>::operator=(*this);
		return *this;
	}

	iterator begin(void) {
		return this->c.begin();
	}
	iterator end(void) {
		return this->c.end();
	}
	
	const_iterator cbegin(void) {
		return this->c.cbegin();
	}
	const_iterator cend(void) {
		return this->c.cend();
	}

	reverse_iterator rbegin(void) {
		return this->c.rbegin();
	}
	reverse_iterator rend(void) {
		return this->c.rend();
	}

	const_reverse_iterator crbegin(void) {
		return this->c.crbegin();
	}
	const_reverse_iterator crend(void) {
		return this->c.crend();
	}
};

#endif