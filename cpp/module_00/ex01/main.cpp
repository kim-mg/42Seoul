/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myunkim <myunkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 16:35:43 by myunkim           #+#    #+#             */
/*   Updated: 2022/07/27 22:15:19 by myunkim          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstring>
#include <iomanip>

class cont_act {
private:
	std::string first_name_;
	std::string last_name_;
	std::string nickname_;
	std::string phone_number_;
	std::string darkest_secret_;

public:
	static int size_;
	void set_data(int, std::string*);
	std::string get_data(int) const;

	cont_act();
	~cont_act();
};

void cont_act::set_data(int data_type, std::string* data) {
	if (data_type == 1)
		first_name_ = *data;
	if (data_type == 2)
		last_name_ = *data;
	if (data_type == 3)
		nickname_ = *data;
	if (data_type == 4)
		phone_number_ = *data;
	if (data_type == 5)
		darkest_secret_ = *data;
}

std::string cont_act::get_data(int data_type) const {
	if (data_type == 1)
		return first_name_;
	if (data_type == 2)
		return last_name_;
	if (data_type == 3)
		return nickname_;
	if (data_type == 4)
		return phone_number_;
	if (data_type == 5)
		return darkest_secret_;
	return NULL;
}

cont_act::cont_act() {
}

cont_act::~cont_act() {
}

class PhoneBook {
private:
	cont_act cont_[8];

	std::string truncate(std::string);
	void find_proc(void);

public:
	static int cur_;
	void add_proc(void);
	void search_proc(void);
	
	PhoneBook();
	~PhoneBook();
};

std::string PhoneBook::truncate(std::string s) {
	if (s.length() > 10) {
		s[9] = '.';
		s.erase(10);
	}
	return s;
}

void PhoneBook::add_proc(void) {
	std::string str;

	std::cout << std::endl << "1. first name : ";
	getline(std::cin, str);
	cont_[cur_].set_data(1, &str);
	std::cout << "2. last name : ";
	getline(std::cin, str);
	cont_[cur_].set_data(2, &str);
	std::cout << "3. nickname : ";
	getline(std::cin, str);
	cont_[cur_].set_data(3, &str);
	std::cout << "4. phone number : ";
	getline(std::cin, str);
	cont_[cur_].set_data(4, &str);
	std::cout << "5. darkest secret : ";
	getline(std::cin, str);
	cont_[cur_].set_data(5, &str);
	cur_++;
	cur_ %= 8;
	cont_[cur_].size_++;
	cont_[cur_].size_ %= 8;
}

void PhoneBook::find_proc(void) {
	int idx;
	int &size = cont_[0].size_;

	while (true) {
		std::cout << std::endl << "search from index (exit is 'e') : ";
		std::cin >> idx;
		if (std::cin.fail() || idx > size) {
			std::cin.clear();
			std::cout << "wrong index" << std::endl << std::endl;
			continue ;
		}
		break ;
	}
	if (idx == 'e')
		return ;
	std::cout << std::endl
		<< "1. first name : " << cont_[idx - 1].get_data(1) << std::endl
		<< "2. last name : " << cont_[idx - 1].get_data(2) << std::endl
		<< "3. nickname : " << cont_[idx - 1].get_data(3) << std::endl
		<< "4. phone number : " << cont_[idx - 1].get_data(4) << std::endl
		<< "5. darkest secret : " << cont_[idx - 1].get_data(5) << std::endl
		<< std::endl;
}

void PhoneBook::search_proc(void) {
	int& size = cont_[0].size_;

	if (!size) {
		std::cout << "empty book" << std::endl;
		return ;
	}
	std::cout << std::endl << "|"
		<< std::setw(10) << std::setfill(' ') << "index" << "|"
		<< std::setw(10) << std::setfill(' ') << "first name" << "|"
		<< std::setw(10) << std::setfill(' ') << "last name" << "|"
		<< std::setw(10) << std::setfill(' ') << "nickname" << "|"
		<< std::endl;
	for (int i = 0; i < size ; i++) {
		std::cout << "|"
			<< std::setw(10) << std::setfill(' ') << i + 1 << "|"
			<< std::setw(10) << std::setfill(' ') << truncate(cont_[i].get_data(1)) << "|"
			<< std::setw(10) << std::setfill(' ') << truncate(cont_[i].get_data(2)) << "|"
			<< std::setw(10) << std::setfill(' ') << truncate(cont_[i].get_data(3)) << "|"
			<< std::endl;
	}
	// find_proc();
}

PhoneBook::PhoneBook() {
}

PhoneBook::~PhoneBook() {
}

int PhoneBook::cur_ = 0;
int cont_act::size_ = 0;

int	main() {
	std::string cmd;
	PhoneBook pb;

	while (true) {
		std::cout << "Phonebook: ";
		std::getline(std::cin, cmd);
		if (!cmd.compare("EXIT"))
			exit(0);
		else if (!cmd.compare("ADD"))
			pb.add_proc();
		else if (!cmd.compare("SEARCH"))
			pb.search_proc();
		else
			std::cout << "usage : EXIT, ADD, SEARCH" << std::endl;
	}
	return 0;
}
