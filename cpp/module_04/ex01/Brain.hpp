#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>

#define RED			"\e[31m"
#define GREEN		"\e[32m"
#define YELLOW		"\e[33m"
#define BLUE		"\e[34m"
#define MAGENTA		"\e[35m"
#define NORMAL		"\e[0m"

class Brain {
public:
	Brain(void);
	Brain(const Brain& src);
	~Brain(void);

	Brain& operator=(const Brain& src);

	void setIdea(const int& i, const std::string& idea);
	std::string getIdea(const int& i) const;
	
	void showBrain(void) const;

private:
	std::string _ideas[100];

	std::string newIdea(void) const;
};

#endif