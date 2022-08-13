#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>
#include <string>

#define RED			"\e[31m"
#define GREEN		"\e[32m"
#define YELLOW		"\e[33m"
#define BLUE		"\e[34m"
#define MAGENTA		"\e[35m"
#define NORMAL		"\e[0m"

class WrongAnimal {
public:
	WrongAnimal(void);
	WrongAnimal(const WrongAnimal& src);
	virtual ~WrongAnimal(void);

	WrongAnimal& operator=(const WrongAnimal& src);

	void setType(const std::string& type);
	std::string getType(void) const;

	void makeSound(void) const;

protected:
	std::string _type;
};

#endif