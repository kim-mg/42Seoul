#include "MutantStack.hpp"

#include <iostream>
#include <stack>
#include <list>

template <typename T>
void test_mstack(MutantStack<T>& mstack) {
	mstack.push(5);
	mstack.push(17);

	std::cout << "MutantStack mstack.top : " << mstack.top() << std::endl;

	mstack.pop();

	std::cout << "MutantStack mstack.size : " << mstack.size() << std::endl;
	std::cout << "MutantStack mstack.empty : " << mstack.empty() << std::endl << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}

	std::cout << std::endl;
}

template <typename T>
void test_stack(MutantStack<T>& mstack) {
	std::stack<int> s(mstack);

	std::cout << "stack s.top : " << s.top() << std::endl;
	std::cout << "stack s.size : " << s.size() << std::endl;

	s.pop();
	s.pop();
	s.push(17);
	s.push(19);

	std::cout << "stack s.top : " << s.top() << std::endl;
	std::cout << "stack s.size : " << s.size() << std::endl << std::endl;
	std::cout << std::endl;
}

template <typename T>
void test_list(MutantStack<T>& mstack) {
	std::list<int> l(mstack.begin(), mstack.end());

	l.push_back(173);
	l.push_front(111);
	l.pop_back();
	l.pop_back();
	l.push_back(222);

	std::list<int>::iterator lit = l.begin();
	std::list<int>::iterator lite = l.end();

	while (lit != lite) {
		std::cout << *lit << std::endl;
		++lit;
	}
}

int main(void) {
	MutantStack<int> mstack;
	test_mstack(mstack);
	test_stack(mstack);
	test_list(mstack);
	return 0;
}