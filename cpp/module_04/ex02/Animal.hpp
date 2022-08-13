#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>

#define RED			"\e[31m"
#define GREEN		"\e[32m"
#define YELLOW		"\e[33m"
#define BLUE		"\e[34m"
#define MAGENTA		"\e[35m"
#define NORMAL		"\e[0m"

class Animal {
public:
	Animal(void);
	Animal(const Animal& src);
	virtual ~Animal(void);

	Animal& operator=(const Animal& src);

	void setType(const std::string& type);
	std::string getType(void) const;

	virtual void makeSound(void) const = 0;

protected:
	std::string _type;
};

#endif